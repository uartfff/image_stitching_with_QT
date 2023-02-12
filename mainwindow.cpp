/******************************************************************************
 * mainwindow.cpp
 * Creates the outer wrapper UI and performs some basic image manipulations.
 * This is where the bulk of operations go; Unless something needs a special
 * dialog, it's probably stuffed here.
 * Author: Yao Guo.
 * Date of first commit: 10 Apr, 2019
 * Knonw Issues: None.
 *****************************************************************************/
#include "ui_mainwindow.h"
#include "ui_imgresizedialog.h"
#include "ui_ParameterDialog.h"
#include "ui_LocalStitching.h"
#include "mainwindow.h"

#include "imgwin.h"
#include "imgabout.h"

#include <QMdiArea>
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QComboBox>
#include <QLineEdit>
#include <QTextStream>
#include <QtMath>
#include <QPen>
#include<QPainter>
#include <iostream>
#include <iomanip> 
#include <omp.h>
#include "time.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include "opencv2/opencv_modules.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/stitching/detail/autocalib.hpp"
#include "opencv2/stitching/detail/blenders.hpp"
#include "opencv2/stitching/detail/camera.hpp"
#include "opencv2/stitching/detail/exposure_compensate.hpp"
#include "opencv2/stitching/detail/matchers.hpp"
#include "opencv2/stitching/detail/motion_estimators.hpp"
#include "opencv2/stitching/detail/seam_finders.hpp"
#include "opencv2/stitching/detail/util.hpp"
#include "opencv2/stitching/detail/warpers.hpp"
#include "opencv2/stitching/warpers.hpp"
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/ml.hpp>

#include "../generatingData/includes.h"
#include "../generatingData/calibres.h"
#define PI 3.1415926

using namespace std;
using namespace cv;
using namespace cv::detail;

clock_t start, finish;
bool try_gpu = true;

vector<string> allImages;
double work_megapix = 0.6;
double seam_megapix = 0.1;
WaveCorrectKind wave_correct = detail::WAVE_CORRECT_HORIZ;
int expos_comp_type = ExposureCompensator::GAIN_BLOCKS;
string result_multi = "result_multi.png";
double work_scale = 1, seam_scale = 1, compose_scale = 1, down_scale = 1;
bool is_work_scale_set = false, is_seam_scale_set = false, is_compose_scale_set = true;//false;//compose:���ղ���;seam:�ನ���ں�
Ptr<FeaturesFinder> featureFinder;
Ptr<WarperCreator> warperCreator;
Ptr<SeamFinder> seamFinder;
vector<Mat> imgs;
int const BUF_LEN = 128;
int mid;

int left_press_num;
float calib_factor_avg = 0;
float calib_factor = 0;
bool Measure_start;


//ImgWin* win = new ImgWin;
QImage cvMat2QImage(const cv::Mat& mat);
QVector<QPoint> measure_point;




/******************************************************************************
 * MainWindow(QWidget*): Creates the MainWindow class
 * Creates the main window, passing the parent to QMainWindow, and initializing
 * the ui.
 *****************************************************************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	//���Ӳ˵�ͼ��
	ui->actionOpen->setIcon(QIcon(":/myimages/images/open.png"));
	ui->actionSave->setIcon(QIcon(":/myimages/images/save.png"));
	ui->actionQuit->setIcon(QIcon(":/myimages/images/exit.png"));
	ui->actionRevert->setIcon(QIcon(":/myimages/images/fanzhuan.png"));
	ui->actionImage_Info->setIcon(QIcon(":/myimages/images/info.png"));
	ui->actionImage_Info->setIcon(QIcon(":/myimages/images/info.png"));
	ui->actionResize->setIcon(QIcon(":/myimages/images/resize.png"));
	ui->actionFit_window->setIcon(QIcon(":/myimages/images/fit.png"));
	ui->actionParameter_setting->setIcon(QIcon(":/myimages/images/setting.png"));
	ui->actionStart->setIcon(QIcon(":/myimages/images/run.png"));
	ui->actionAbout->setIcon(QIcon(":/myimages/images/help.png"));
	ui->actionMeasure->setIcon(QIcon(":/myimages/images/measure.png"));
	ui->actionNeighborStitching->setIcon(QIcon(":/myimages/images/neighborStitching.png"));
	ui->actionNeighbor_stitch->setIcon(QIcon(":/myimages/images/neighborStitching.png"));
	ui->actiongenerating_data->setIcon(QIcon(":/myimages/images/generatingData.png"));
	setWindowIcon(QIcon(":/myimages/images/window.png"));
	// Add a box in the status bar to show the color under the cursor
    status_color_swatch = new QLabel();
    QPalette pal = status_color_swatch->palette();
    pal.setColor(status_color_swatch->backgroundRole(), Qt::black);
    status_color_swatch->setPalette(pal);
    status_color_swatch->setAutoFillBackground(true);
    status_color_swatch->setMinimumSize(50,5);
    ui->statusBar->addPermanentWidget(status_color_swatch);

    // Add a drop-down box to select common zoom sizes or to type in your own size
    zoom_box = new QComboBox();
    zoom_box->addItem("300");
    zoom_box->addItem("200");
    zoom_box->addItem("150");
    zoom_box->addItem("100");
    zoom_box->addItem("75");
    zoom_box->addItem("50");
    zoom_box->addItem("25");
    zoom_box->addItem("10");
    zoom_box->setInsertPolicy(QComboBox::NoInsert);
    zoom_box->setValidator(new QIntValidator(10,300,zoom_box));
    zoom_box->setEditable(true);
    zoom_box->setEnabled(false);

    ui->toolBar->addWidget(zoom_box);

    // Add a spacer on the toolbar
    QWidget *w = new QWidget();
    w->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    w->setMinimumSize(4, 4);
    ui->toolBar->addWidget(w);

    // Add a slider to control zoom as well
    zoom_slider = new QSlider(Qt::Vertical);
    zoom_slider->setRange(10, 300);
    zoom_slider->setSingleStep(10);
    zoom_slider->setValue(100);
    zoom_slider->setTickInterval(40);
    zoom_slider->setTickPosition(QSlider::TicksRight);
    zoom_slider->setEnabled(false);
    zoom_slider->setMinimumWidth(40);
    zoom_slider->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // Note, if you move the toolbar, the slider changes direction :)
    zoom_slider->connect(ui->toolBar, SIGNAL(orientationChanged(Qt::Orientation)), SLOT(setOrientation(Qt::Orientation)));

    ui->toolBar->addWidget(zoom_slider);
    // Also, you can resize to fit the window
    ui->toolBar->addAction(ui->actionFit_window);

	ui->actionParameter_setting->setEnabled(false);
	ui->actionStart->setEnabled(false);
	ui->actionMeasure->setEnabled(false);

    // Sync the combo box and slider
    connect(zoom_box, SIGNAL(editTextChanged(QString)), SLOT(zoomBoxChanged(QString)));
    connect(zoom_box, SIGNAL(activated(QString)), SLOT(zoomBoxChanged(QString)));
}

/******************************************************************************
 * ~MainWindow(): Destructor
 * Deletes the ui.
 *****************************************************************************/
MainWindow::~MainWindow()
{
    delete ui;
}



Mat get_matchmask(const char* cvs_file_name, Size mask_size)
{
	//Ӧ�������������ƥ�����
	//��ȡcsv�ļ�
	CvMLData mlData;    //csv�ļ��а���������ͼ�����е�λ�ù�ϵ
	int a=mlData.read_csv(cvs_file_name);
	cv::Mat data = cv::Mat(mlData.get_values(), true);
	Mat matchMask = Mat::zeros(mask_size, CV_8U);  //mask_size�Ƕ�ά����

	if (data.empty()) {  //�����ͼ�����е�λ����Ϣ��������ƴ�ӣ���������ͼ��Ҫ��������ƴ��
		matchMask = Mat::ones(mask_size, CV_8U);
		for (int i = 0; i < matchMask.rows; i++) {
			for (int j = 0; j < matchMask.cols; j++) {
				if (i == j) { matchMask.at<char>(i, j) = 0; }
			}
		}
		return matchMask;
		/*if (matchMask.rows > matchMask.cols) {
			for (int i = 0; i < matchMask.rows; i++) {
				for (int j = 0; j < matchMask.cols; j++) {
					if (i >= j) { matchMask.at<char>(i, j) = 0; }
				}
			}
		}
		else {
			for (int i = 0; i < matchMask.rows; i++) {
				for (int j = 0; j < matchMask.cols; j++) {
					if (i <= j) { matchMask.at<char>(i, j) = 0; }
				}
			}
		}
		return matchMask;*/
	}
	///////////////////8������////////////////////////////////
	int img_no = mask_size.height;

	//float x[100] = { 0 }, z[100] = { 0 }; float number[100]; int j = 0;
	float x[111] = { 0 }, z[111] = { 0 }; float number[111]; int j = 0;
	for (int i = 1; i <= img_no; i++)
	{

		x[j] = data.at <float>(i, 4);
		z[j] = data.at <float>(i, 5);
		number[j] = data.at <float>(i, 0);
		j++;
	}


	for (int i = 0; i < img_no; i++)
	{
		if (img_no <= 2) { Mat A(mask_size, CV_8U, Scalar(1)); matchMask = A.clone(); break; }
		float dist[100] = { 0 }; int k = 0;
		for (int j = 0; j < img_no; j++)
		{

			long temp = sqrt((x[i] - x[j])*(x[i] - x[j]) + (z[i] - z[j])*(z[i] - z[j]));
			if (temp == 0 || temp < 0)
				continue;
			else
				dist[k] = temp;
			k++;
		}

		int t = (img_no - 1);
		sort(dist, dist + t);
		for (int j = 0; j < img_no; j++)
		{

			long temp = sqrt((x[i] - x[j])*(x[i] - x[j]) + (z[i] - z[j])*(z[i] - z[j]));
			if (temp <= dist[1] && temp>0)
			{
				matchMask.at<char>(i, j) = 1;
			}
		}
	}
	return matchMask;
}

vector<string> getfilename(string folder_name)
{
	string dir_path = folder_name;
	vector<string> fileName;
	Directory dir;
	vector<string> fileNames1 = dir.GetListFiles(dir_path, "*.*", false); //*.bmp

	for (int i = 0; i < fileNames1.size(); i++)
	{
		string fileName1 = fileNames1[i];
		fileName.push_back(fileName1);
	}
	/** Checking the number of images. */
	int img_no = static_cast<int>(fileName.size());
	if (img_no < 2)
	{
		LOGLN("Need more images");
	}
	return fileName;
}



//������ʱ�������ϸ��½�������ֱ����ʱ���ݽ���
void MainWindow::updateProgressDialog()
{
	currentValue++;
	if (currentValue == 100)
		currentValue = 0;
	progDlg->setValue(currentValue);
	QCoreApplication::processEvents();//������涳��
	if (progDlg->wasCanceled())
		progDlg->setHidden(true);//���ضԻ���
}



/******************************************************************************
 * QPixmap* getCurrent(): Get the current image window
 * Private function.
 * Finds the current image window and returns it.
 *****************************************************************************/
ImgWin* MainWindow::getCurrent()
{
    QMdiSubWindow *child = ui->mdiArea->activeSubWindow();
    if (!child)
        return 0;
    return (ImgWin*)(child->widget());
}

/******************************************************************************
 * QImage getImage(): Get the current image window's image
 * Private function.
 * Finds the current image window and returns the image.
 *****************************************************************************/
QImage MainWindow::getImage()
{
    ImgWin *cur = getCurrent();
    if (cur)
        return cur->getImage();
    return QImage();
}

/******************************************************************************
 * setImage(QImage): Set the current image window's image
 * Private function.
 * Finds the current image window and sets the image.
 *****************************************************************************/
void MainWindow::setImage(QImage p)
{
    getCurrent()->setImage(p);
}

/******************************************************************************
 * doOpen(void): Open a document.
 * Slot function.
 * Signalers: actionOpen
 * Attempts to open a document using Qt, and creates a child window for the
 * image. If the user cancels or they choose an invalid file, no window is
 * created.
 *****************************************************************************/
void MainWindow::doOpen()
{
	calib_factor == 0;
	file = QFileDialog::getOpenFileNames(this, "Open Image", "",
		"Image Files (*.png *.jpg *.bmp *.gif);;Any Files (*.*)");
	NumImg = file.length();
	if (NumImg == 0) {
		QMessageBox::critical(this, "error", "Less than 2 images loaded!!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}
	if (file[0] != "")
	{
		QImageReader *reader = new QImageReader(file[0]);//AAAA
		QImage img = reader->read();
		if (!img.isNull())
		{
			ImgWin* win = new ImgWin;
			win->setImage(img);
			win->setWindowTitle(file[0]);
			win->setReader(reader);

			// Display the image window
			QMdiSubWindow* subwin = ui->mdiArea->addSubWindow(win);
			subwin->showMaximized();

			// Add a item to the window menu, and give it to the imgwin to keep track of
			win->setMenuItem(ui->menuWindow->addAction(file[0], subwin, SLOT(setFocus())));
			connect(win, SIGNAL(closing(QAction*)), this, SLOT(removeWindowListItem(QAction*)));

			// Mouse info
			connect(win, SIGNAL(mouseOverInfo(QPoint)),this, SLOT(imgMouseInfo(QPoint)),Qt::UniqueConnection);//, Qt::UniqueConnection
		}
	}

	ui->actionParameter_setting->setEnabled(true);
	ui->actionMeasure->setEnabled(true);
}

/******************************************************************************
 * doSave(void): Save a document.
 * Slot function.
 * Signalers: actionSave
 * Save the current image to the name provided.
 *****************************************************************************/
void MainWindow::doSave()
{
    QString file = QFileDialog::getSaveFileName(this, "Save Image", "", "Image Files (*.png *.jpg *.bmp) ");
	Mat result;
    if (file != "")
    {	
		result = imread("result_multi.png");
		string result_path = file.toStdString();
		imwrite(result_path,result);
		//getImage().save(file);
    }
}


/******************************************************************************
 * doFillWindow(): Change the zoom to hold the whole image.
 * Slot function.
 * Signalers: actionFillWindow()
 * Zoom the image to fit it inside the image window.
 *****************************************************************************/
void MainWindow::doFillWindow()
{
    ImgWin *c = getCurrent();
    c->setScale(std::min(c->contentsRect().width() * 100.0 / getImage().width(),
                         c->contentsRect().height() * 100.0 / getImage().height()));
}


/******************************************************************************
 * doResize(): Resize the image.
 * Slot function.
 * Signalers: actionResize()
 * Launch a dialog box and resize the image to the specified size.
 *****************************************************************************/
void MainWindow::doResize()
{
    QDialog* d = new QDialog(this);
    Ui::ImgResizeDialog* resize = new Ui::ImgResizeDialog;
    resize->setupUi(d);
    resize->widthSpin->setValue(getImage().size().width());
    resize->heightSpin->setValue(getImage().size().height());
    resize->widthSpin->setRange(1,1000000);
    resize->heightSpin->setRange(1,1000000);

    if (d->exec() == QDialog::Accepted)
    {
        setImage(getImage().scaled(QSize(resize->widthSpin->value(),resize->heightSpin->value())));
    }
}

void MainWindow::parameter_setting()
{
    bool aux_info1_temp,aux_info2_temp;
	QDialog* a = new QDialog(this);
	Ui::Dialog* setting = new Ui::Dialog;
	setting->setupUi(a);
	//setting->bends->setRange(1, 50);
	double default_value;
	for (int i = 1; i < 100; i++) { 
		if (((getImage().size().width() / i) < 750)) { default_value = i; break; }
	}
	//����Ĭ��ֵ
	setting->down->setValue(default_value);
	setting->noncoordinates->setChecked(true);
	//���ý���Ľ���������
	int min_multiple = ceil(default_value / 2); //����ȡ��
	int max_multiple = default_value;
	setting->min_multiple->setTextFormat(Qt::RichText);
	setting->min_multiple->setNum(min_multiple);
	setting->max_multiple->setTextFormat(Qt::RichText);
	setting->max_multiple->setNum(max_multiple);

	a->exec();
    //Acquisition of multiple sampling times
	Multiple = setting->down->value();
    //Get the number of bands
	//multiple_bends = setting->bends->value();
	//QDialog *checkBox = new QDialog();

     //aux_info1_temp = setting->checkBox->checkState();
	 aux_info1_temp = setting->coordinates->isChecked();
     //aux_info2_temp = setting->checkBox_2->checkState();
	 aux_info2_temp = setting->noncoordinates->isChecked();
     //extra_way1 = setting->checkBox_3->checkState();
     //extra_way2 = setting->checkBox_4->checkState();
	 is_origin_Resolving = setting->checkBox_6->checkState();
	 
	 if (Multiple < min_multiple)
	 {
		 QMessageBox::warning(this, "Warning", "Greater down-sampling multiple is recommended !", QMessageBox::Yes, QMessageBox::No);
	 }
	 if (Multiple > max_multiple)
	 {
		 QMessageBox::warning(this, "Warning", "Smaller down-sampling multiple is recommended !", QMessageBox::Yes, QMessageBox::No);
	 }
     if (aux_info1_temp == true)
	 {
		Coordinate_path = QFileDialog::getOpenFileName(this, "Coordinate path", "",
				 " Any Files (*.csv)");
	}
    aux_info1 = aux_info1_temp;
    aux_info1 = aux_info1_temp;

	ui->actionStart->setEnabled(true);
}



void MainWindow::stitching()
{
	//vector<string> fileNames;
	string temp;
	double start = clock();
	/** Checking the number of images. */
	int img_no = static_cast<int>(NumImg);
	if (img_no <= 1)
	{
        QMessageBox::critical(this, "error", "Less than 2 images loaded!!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}
	//Directory dir;
	if (fileNames.empty())
	{
		for (int i = 0; i < img_no; i++)
		{
			temp = file[i].toLocal8Bit().data();
			fileNames.push_back(temp);
		}
	}

	if (is_origin_Resolving) { is_compose_scale_set = false; }
	else { is_compose_scale_set = true; }
	//if (extra_way1) { featureFinder = new SurfFeaturesFinder(); }
	//if (extra_way2) { featureFinder = new OrbFeaturesFinder(); }
	//if ((!extra_way1) && (!extra_way2)) { featureFinder = new SurfFeaturesFinder(); }

	featureFinder = new SurfFeaturesFinder();
	//featureFinder = new OrbFeaturesFinder();

	Mat *full_img = new Mat[img_no];
	vector<ImageFeatures> features(img_no);
	//Mat *img = new Mat[img_no];
	//Mat *images = new Mat[img_no];
	vector<Mat> images(img_no);
	vector<Size> full_img_sizes(img_no);
	double seam_work_aspect = 1;

	statusBar()->showMessage("Runing:Loading images and extracting feature points...", 3000000000000);
#pragma omp parallel  for
	for (int i = 0; i < img_no; ++i)
	{
		full_img[i] = imread(fileNames[i]);
		full_img_sizes[i] = full_img[i].size();

		if (full_img[i].empty())
		{
            QMessageBox::critical(this, "error", "The image loaded is empty!!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
			return;
			//continue;
		}
		if (!is_work_scale_set)
		{
			//work_scale = min(1.0, sqrt(work_megapix  * 1e6 / full_img[i].size().area()));
			down_scale = 1 / Multiple;  //Multiple:�²�������
			work_scale = down_scale;
			is_work_scale_set = true;
		}
		cv::resize(full_img[i], images[i], Size(), work_scale, work_scale); //ͼ�����ź���resize(InputArray src, OutputArray dst, Size dsize, double fx=0, double fy=0, int interpolation=INTER_LINEAR )
																			//�������壺
																			//InputArray src - ԭͼ��
																			//	OutputArray dst - ���ͼ��
																			//	Size dsize - Ŀ��ͼ��Ĵ�С
																			//	double fx = 0 - ��x���ϵ����ű���
																			//	double fy = 0 - ��y���ϵ����ű���
																			//	int interpolation - ��ֵ��ʽ�����������ַ�ʽ
																			//	INTER_NN - ����ڲ�ֵ																			
																			//	INTER_LINEAR - ˫���Բ�ֵ(ȱʡʹ��)
																			//	INTER_AREA - ʹ�����ع�ϵ�ز�������ͼ����Сʱ�򣬸÷������Ա��Ⲩ�Ƴ��֡���ͼ��Ŵ�ʱ�������� INTER_NN ������																			//	INTER_CUBIC - ������ֵ
		if (!is_seam_scale_set)												//  INTER_CUBIC   -������ֵ
		{
			//seam_scale = min(1.0, sqrt(seam_megapix * 1e6 / full_img[i].size().area()));
			seam_scale = work_scale;
			seam_work_aspect = seam_scale / work_scale;
			is_seam_scale_set = true;
		}

		(*featureFinder)(images[i], features[i]);
		//(*featureFinder)(img, features[i]);
		features[i].img_idx = i;
		//cv::resize(full_img[i], images[i], Size(), down_scale, down_scale);

	}
	featureFinder->collectGarbage(); //�����ڴ�

	Mat matchMask(features.size(), features.size(), CV_8U, Scalar(0));

	//������Ϣ�ļ�·��(����û��)
	std::string str_path = Coordinate_path.toStdString();
	const char* cvs_file_name = str_path.c_str();

	matchMask = get_matchmask(cvs_file_name, matchMask.size());

	vector<MatchesInfo> pairwise_matches;
	BestOf2NearestMatcher matcher(try_gpu, 0.5f);//��0.5f�ĳ���0.3f

	statusBar()->showMessage("Runing:Feature point matching...", 3000000000000);
	matcher(features, pairwise_matches, matchMask);//
	matcher.collectGarbage();


	//�����Ѿ�ƥ��õ������ԣ��ж���ЩͼƬ���������У���ЩͼƬ�ǲ���������
	vector<int> indices = leaveBiggestComponent(features, pairwise_matches, 0.4f);//ƥ���������ֵ
	vector<Mat> img_subset;	
	vector<string> img_names_subset;	
	vector<Size> full_img_sizes_subset;	
	for (size_t i = 0; i < indices.size(); ++i) 
	{ 
		img_names_subset.push_back(fileNames[indices[i]]);
		img_subset.push_back(images[indices[i]]);		
		full_img_sizes_subset.push_back(full_img_sizes[indices[i]]); 
	} 	
	images = img_subset;	
	fileNames = img_names_subset;
	full_img_sizes = full_img_sizes_subset;

	//�ٴμ��ͼ����Ŀ�Ƿ�����Ҫ��
	img_no = static_cast<int>(fileNames.size());
	if (img_no < 2)
	{
        QMessageBox::critical(this, "error", "Less than 2 images left after feature point matching !", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}



	statusBar()->showMessage("Runing:Camera parameter estimation and adjustment...", 3000000000000);
	/** Estimate the camera rotation between all the images. *///�õ��������
	HomographyBasedEstimator estimator;
	vector<CameraParams> cameras, cameras_temp;
	estimator(features, pairwise_matches, cameras);
	//cameras_temp = cameras;

	vector<Mat> R(img_no);
#pragma omp parallel  for	
	for (int i = 0; i < cameras.size(); ++i)
	{
		cameras[i].R.convertTo(R[i], CV_32F);
		cameras[i].R = R[i];
	}
	cameras_temp = cameras;
	R.clear();
	/** Performing image alignment. *///ʹ��Bundle Adjustment����������ͼƬ�����������У��
	Ptr<detail::BundleAdjusterBase> adjuster;
	adjuster = new detail::BundleAdjusterRay();

	adjuster->setConfThresh(1.0f);
	Mat_<uchar> refine_mask = Mat::zeros(3, 3, CV_8U);
	//#pragma omp parallel  for	
	for (int k = 0; k<2; k++)
	{
		for (int j = 0; j<3; j++)
		{
			refine_mask(k, j) = 1;
		}
	}
	adjuster->setRefinementMask(refine_mask);	


	statusBar()->showMessage("Runing:bundle adjustment...", 3000000000000);
	(*adjuster)(features, pairwise_matches, cameras);//ʹ��Bundle Adjustment����������ͼƬ�����������У��

	if (isnan(cameras[0].focal)) { cameras_temp[0].R= cv::Mat::eye(cv::Size(3, 3), CV_32FC1);
	cameras = cameras_temp; }

	//	if (cameras[0].focal) { cameras = cameras_temp; }

	if (cameras.size() != img_no) {
		QMessageBox::critical(this, "error", "Bundle adjustment optimization error! please check whether the scale of input image is consistent !", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}
													 
	/** Find median focal length. */// ����Ľ���ȡ��ֵ������ͼƬ�Ľ��ಢ����camera������������д��camera
	vector<double> focals;

	for (long i = 0; i < cameras.size(); ++i)
	{
		focals.push_back(cameras[i].focal);
	}
	sort(focals.begin(), focals.end());
	float warped_image_scale;
	if (focals.size() % 2 == 1)
		warped_image_scale = static_cast<float>(focals[focals.size() / 2]);
	else
		warped_image_scale = static_cast<float>(focals[focals.size() / 2 - 1] + focals[focals.size() / 2]) * 0.5f;
	focals.clear();


	statusBar()->showMessage("Runing:Waveform correction...", 3000000000000);
	/** Perform image straightening using wave correction (horizontal wave correction) *////���ν���
	if (true)
	{
		vector<Mat> rmats;
		for (size_t i = 0; i < cameras.size(); ++i)
			rmats.push_back(cameras[i].R);
		waveCorrect(rmats, wave_correct);
		for (int i = 0; i < cameras.size(); ++i)
			cameras[i].R = rmats[i];
	}


	statusBar()->showMessage("Runing:Prepare curved images and blend masks...", 3000000000000);
	vector<Point> corners(img_no);//ͳһ�����Ķ���
	vector<Mat> masks_warped(img_no);
	vector<Mat> images_warped(img_no);
	vector<Size> sizes(img_no);
	Mat *masks = new Mat[img_no];

	/** Preapre masks for each image. */
	for (int i = 0; i < img_no; ++i)
	{
		masks[i].create(images[i].size(), CV_8U);
		masks[i].setTo(Scalar::all(255));
	}

	/** Warp the images and their masks. Using Spherical warping. *///����ͼ����ں����� 
	//warperCreator = new cv::SphericalWarper(); //����ͶӰ
	//warperCreator=new cv::CylindricalWarper(); //����ͶӰ
	//warperCreator=new cv::PlaneWarper(); //ƽ��ͶӰ
	warperCreator = new cv::PaniniWarper();//����ͶӰ
	Ptr<RotationWarper> warper = warperCreator->create(static_cast<float>(warped_image_scale * seam_work_aspect));

#pragma omp parallel  for
	for (int i = 0; i < img_no; ++i)
	{
		Mat_<float> K;
		cameras[i].K().convertTo(K, CV_32F);
		/*K[i](0, 0) *= seam_work_aspect; K[i](0, 2) *= seam_work_aspect;
		K[i](1, 1) *= seam_work_aspect; K[i](1, 2) *= seam_work_aspect;*/
		float swa = (float)seam_work_aspect;
		K(0, 0) *= swa; K(0, 2) *= swa;
		K(1, 1) *= swa; K(1, 2) *= swa;

		corners[i] = warper->warp(images[i], K, cameras[i].R, INTER_LINEAR, BORDER_REFLECT, images_warped[i]);//����ͳһ�����궥��
		sizes[i] = images_warped[i].size();
		warper->warp(masks[i], K, cameras[i].R, INTER_NEAREST, BORDER_CONSTANT, masks_warped[i]);
		/*** warp(const Mat& src, const Mat& K, const Mat& R, int interp_mode, int border_mode, Mat& dst)
		Parameters:
		src �C ԭͼ��
		K �C ����ڲ�
		R �C �������ת����
		interp_mode �C Interpolation mode
		border_mode �C Border extrapolation mode
		dst �C ͶӰ�任���ͼ��
		����ֵ :ͶӰ�任���ͼ������Ͻ�  ***/

		if ((images_warped[i].cols*images_warped[i].rows > 9 * images[i].cols*images[i].rows) || ((images[i].cols > 2000 || images[i].rows > 2000) && img_no > 9))
		{
			QMessageBox::critical(this, "error", "Run out of memory! Select less images or proper images", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
			return;
		}
	}

	vector<Mat> images_warped_f(img_no);
//#pragma omp parallel  for
	for (int i = 0; i < img_no; ++i)
	{
		images_warped[i].convertTo(images_warped_f[i], CV_32F);
	}

	Ptr<ExposureCompensator> compensator = ExposureCompensator::createDefault(ExposureCompensator::GAIN);
	// createDefault(ExposureCompensator::NO/GAIN/GAIN_BLOCKS)
	// NO ��ʾ�������عⲹ��
	// GAIN ��ʾӦ�����油�����������عⲹ��
	// GAIN_BLOCKS ��ʾӦ�÷ֿ鲹�����������عⲹ��
	compensator->feed(corners, images_warped, masks_warped); //�õ��عⲹ����
	//for (int i = 0; i < img_no; i++)
	//{
	//	compensator->apply(i,corners[i], images_warped[i], masks_warped[i]); //Ӧ���عⲹ��������ͼ������عⲹ��
	//}

	//seamFinder = new detail::GraphCutSeamFinder(GraphCutSeamFinderBase::COST_COLOR);
	//seamFinder = new detail::DpSeamFinder(DpSeamFinder::COLOR_GRAD);
	//seamFinder = new NoSeamFinder();    //����Ѱ�ҽӷ���   
	//seamFinder = new VoronoiSeamFinder();    //��㷨   
	//seamFinder = new DpSeamFinder(DpSeamFinder::COLOR);    //��̬�滯��   
	seamFinder = new DpSeamFinder(DpSeamFinder::COLOR_GRAD);   
	//ͼ�   
	//seamFinder = new GraphCutSeamFinder(GraphCutSeamFinder::COST_COLOR);
	//seamFinder = new GraphCutSeamFinder(GraphCutSeamFinder::COST_COLOR_GRAD);

	seamFinder->find(images_warped_f, corners, masks_warped); //Ѱ��ͼ�������ƴ�ӷ�

	Mat img_warped, img_warped_s;
	Mat dilated_mask, seam_mask, mask, mask_warped;
	Ptr<Blender> blender_multi;
	double compose_work_aspect = 1;
	Mat  img1;
	if (!is_compose_scale_set)
	{
		compose_work_aspect = Multiple;
		warped_image_scale *= static_cast<float>(compose_work_aspect);
		warper = warperCreator->create(warped_image_scale);

		/** Update corners and sizes of each image*/

		for (int i = 0; i < img_no; ++i)
		{
			cameras[i].focal *= compose_work_aspect;
			cameras[i].ppx *= compose_work_aspect;
			cameras[i].ppy *= compose_work_aspect;

			Size sz = full_img_sizes[i];
			if (std::abs(compose_scale - 1) > 1e-1)
			{
				sz.width = cvRound(full_img_sizes[i].width * compose_scale);
				sz.height = cvRound(full_img_sizes[i].height * compose_scale);
			}

			Mat K;
			cameras[i].K().convertTo(K, CV_32F);
			Rect roi = warper->warpRoi(sz, K, cameras[i].R);
			corners[i] = roi.tl();
			sizes[i] = roi.size();
		}
	}

	full_img_sizes.clear();

	statusBar()->showMessage("Runing:Image adjustment and fusion...", 3000000000000);
	//��ʼ��blender  
	if (blender_multi.empty())
	{
		int blend_type_multi = Blender::MULTI_BAND;//�ನ���ںϷ�
		blender_multi = Blender::createDefault(blend_type_multi, false);
		Size dst_sz = resultRoi(corners, sizes).size();
		float blend_width = sqrt(static_cast<float>(dst_sz.area())) * 5 / 100.f;
		MultiBandBlender* mb = dynamic_cast<MultiBandBlender*>(static_cast<Blender*>(blender_multi));
		mb->setNumBands(6);

		//int blend_type_multi = Blender::FEATHER;//���ںϷ�
		//blender_multi = Blender::createDefault(blend_type_multi, false);
		//FeatherBlender* fb = dynamic_cast<FeatherBlender*>(static_cast<Blender*>(blender_multi));
		//fb->setSharpness(0.005);    //���������

		blender_multi->prepare(corners, sizes);
	}
	
	vector<Mat>optimal_seam;


	for (int img_idx = 0; img_idx < img_no; ++img_idx)
	{
		if (is_compose_scale_set)
			//resize(full_img[img_idx], img1, Size(), compose_scale, compose_scale);
			img1 = images[img_idx];
		else
			img1 = full_img[img_idx];
		Size img_size = img1.size();

		Mat K;
		cameras[img_idx].K().convertTo(K, CV_32F);
		// Ť����ǰͼ��  
		warper->warp(img1, K, cameras[img_idx].R, INTER_LINEAR, BORDER_REFLECT, img_warped);
		
		// Ť����ǰͼ����ģ  
		mask.create(img_size, CV_8U);
		mask.setTo(Scalar::all(255));
		warper->warp(mask, K, cameras[img_idx].R, INTER_NEAREST, BORDER_CONSTANT, mask_warped);

		// �عⲹ��  
		compensator->apply(img_idx, corners[img_idx], img_warped, mask_warped);

		img_warped.convertTo(img_warped_s, CV_16S);
		img_warped.release();
		//img.release();
		mask.release();

		dilate(masks_warped[img_idx], dilated_mask, Mat());
		cv::resize(dilated_mask, seam_mask, mask_warped.size());
		cv::imshow("seam",seam_mask);
		cv::imwrite("seam"+to_string(img_idx)+".png", seam_mask);
		mask_warped = seam_mask & mask_warped;

		optimal_seam.push_back(seam_mask);

		/// �ںϵ�ǰͼ��  
		blender_multi->feed(img_warped_s, mask_warped, corners[img_idx]);
		imwrite("blendMask.png", mask_warped);
		imwrite("image_warped" + to_string(img_idx) + ".png", img_warped_s);

		/*cout << "ͳһ�����ͼ��" << to_string(img_idx + 1) << "�����Ͻ�����Ϊ:"
			<< "(" << corners[img_idx].x << "," << corners[img_idx].y << ")" << endl;
		cout << "�ںϺ��ԭͼ���СΪ:" << 
			"W:" << sizes[img_idx].width << " " << "H:" << sizes[img_idx].height << endl;*/

	}

	Mat result_multi_img, result_mask;
	QImage imgtemp;

	//blender_feather->blend(result_feather_img, result_mask);
	blender_multi->blend(result_multi_img, result_mask);
	cv::imwrite("result_mask.png", result_mask);
	cv::imwrite(result_multi, result_multi_img);

	//ͨ��canny��Ե��⣬�õ�����߽磬������һ���߽���ǽӷ���   
	for(int k=0;k< img_no;k++)
		Canny(optimal_seam[k], optimal_seam[k], 1, 1,3 );     
	//Ϊ��ʹ�ӷ��߿��ø����������ʹ���������������Ӵֱ߽���   
	vector<Mat> dilate_image(img_no);
	//Mat element = getStructuringElement(MORPH_RECT, Size(10, 10));    //����ṹԪ��    
	Mat element = getStructuringElement(MORPH_CROSS, Size(2, 2));
    
	dilate(optimal_seam[0], dilate_image[0],element);    //��������
	//��ӳ��任ͼ�ϻ����ӷ��ߣ�������ֻ��Ϊ�˳��ֳ���һ��Ч�������Բ�û�����ֽӷ��ߺ���������߽�      
	for (int i = 0; i < dilate_image[0].rows; i++)
	{
		for (int j = 0; j < dilate_image[0].cols; j++)
		{
			if (dilate_image[0].at<uchar>(i, j) == 255)    //����߽�           
			{
				result_multi_img.at<Vec3b>(i, j)[0] = 0;
				result_multi_img.at<Vec3b>(i, j)[1] = 255;
				result_multi_img.at<Vec3b>(i, j)[2] = 0;
			}
		}
	}

	cv::imwrite("result_image_with_seam.png", result_multi_img);
	//�ڽ��ͼ����ʾͼ��ƴ�ӷ�

	QString A0 = "result_multi.png";
	QImageReader *reader1 = new QImageReader(A0);
	QImage img0 = reader1->read();
	if (!img0.isNull())
	{
		ImgWin* win = new ImgWin;
		win->setImage(img0);
		win->setWindowTitle(A0);
		win->setReader(reader1);

		// Display the image window
		QMdiSubWindow* subwin = ui->mdiArea->addSubWindow(win);
		subwin->showMaximized();
	}


	finish = clock();
	double duration = ((finish - start) / CLOCKS_PER_SEC);
	//cout << "�ܺ�ʱ:" << duration << endl;
	statusBar()->showMessage("Stitching completion...", 3000000000000);

	string stemp;
	char str[256];
	sprintf(str, "%lf", duration);
	stemp = str;
	temp = "image mosaicking consuming is";
	string temp0 = temp +' '+ stemp + ' ' +'s';
	QString temp1 = QString::fromStdString(temp0);//toLocal8Bit().data()
	QMessageBox::information(this, tr("Stitching completed"), QString(temp1), QMessageBox::Yes, QMessageBox::No);

	ui->actionParameter_setting->setEnabled(false);
	

	delete[] full_img;
	//delete[] images;
	images.clear();
	images_warped.clear();
	images_warped_f.clear();
	delete[] masks;
	cameras.clear();
	corners.clear();
	masks_warped.clear();
	sizes.clear();
	img_warped_s.release();
	dilated_mask.release();
	seam_mask.release();
	mask_warped.release();
}

void MainWindow::start()
{	
	ui->actionStart->setIcon(QIcon(":/myimages/images/kaishi.png"));
	stitching();
	ui->actionStart->setIcon(QIcon(":/myimages/images/run.png"));

	ui->actionStart->setEnabled(false);
}



/******************************************************************************
 * doAbout(): Show about dialog.
 * Slot function.
 * Signalers: actionAbout()
 * Shows the About dialog from aboutdialog.ui.
 *****************************************************************************/
void MainWindow::doAbout()
{
    QMessageBox::information(this, "About",
        "A image mosaic application.\n"
        "Copyright 2018 Huajian Rui and 2019 YaoGuo.");
}

/*******************************************************************************
 * doInfo(): Show a dialog containing basic image info.
 * Slot function.
 * Signalers: actionInfo()
 * Shows the Image Info dialog from imageInfo.ui and sets the fields.
 ******************************************************************************/
void MainWindow::doInfo()
{
    imgAbout *d = new imgAbout();
    QMdiSubWindow *child = ui->mdiArea->activeSubWindow();
    ImgWin *win = (ImgWin*)(child->widget());
    d->setup(win);
    d->show();
}

/******************************************************************************
 * doChangeImage(QMdiSubWindow*): Handles window switching.
 * Slot function.
 * Signalers: QMdiArea->SubWindowActivated(QMdiSubWindow*)
 * Changes the enabled state of the edit menu when the last window is closed.
 *****************************************************************************/
void MainWindow::doChangeImage(QMdiSubWindow* win)
{
    ui->statusBar->clearMessage();

    zoom_box->setDisabled(win == 0);
    zoom_slider->setDisabled(win == 0);
    zoom_slider->disconnect();
    connect(zoom_slider, SIGNAL(valueChanged(int)), SLOT(zoomChanged(int)));
    if (win)
    {
        ImgWin *c = getCurrent();

        zoom_slider->setValue(c->getScale());
        zoom_box->setEditText(QString::number(c->getScale()));
        c->connect(zoom_slider, SIGNAL(valueChanged(int)), SLOT(setScale(int)));
        zoom_slider->connect(c, SIGNAL(scaleChanged(int)), SLOT(setValue(int)));
    }

    emit imageEditable(win != 0);
}


 //��갴���¼�
//void MainWindow::mousePressEvent(QMouseEvent *event)
//{
//	// ���������������   �ı�ָ����״�����Ҵ洢��ǰָ��λ���봰��λ�õĲ�ֵ��
//	if (event->button() == Qt::LeftButton) 
//	{
//		left_press_num += 1;
//	}
//}



void MainWindow::ShowMeasureRes(QVector<QPoint> point0,float calib_factor)
{
	ImgWin* win_cur = getCurrent();
	QRect sel = win_cur->getSelection();
	if (point0.size() == 2 && sel.isEmpty())
	{
		QPainter painter(win_cur);
		QPen pen;
		pen.setColor(QColor(Qt::red));
		pen.setWidth(3);
		painter.setPen(pen);
		painter.drawLine(point0[0], point0[1]);
		
		QPoint dis;
		float real_dis;
		float pixel_dis;
		dis.setX(point0[0].x() - point0[1].x());
		dis.setY(point0[0].y() - point0[1].y());
		pixel_dis = qSqrt(dis.x()*dis.x() + dis.y()*dis.y());
		real_dis = calib_factor*pixel_dis;
		QMessageBox msgBox;

		QString info = QString("The pixel distance is %1 pix").arg(pixel_dis)+"\n"+ QString("The pixel factor is %2 mm/pix").arg(calib_factor) + "\n"+ QString("The real distance is %3 mm").arg(real_dis);
		msgBox.setWindowTitle("Line Measurement Result");
		msgBox.setText(info);
		msgBox.exec();
		measure_point.clear();
	}
	if (point0.size() != 2 && !sel.isEmpty())
	{

		float real_x,real_y,real_area;
		float pixel_x,pixel_y,pixel_area;

		pixel_x = sel.width();
		pixel_y = sel.height();
		pixel_area = pixel_x*pixel_y;
		real_x = pixel_x*calib_factor;
		real_y = pixel_y*calib_factor;
		real_area = pixel_area*calib_factor;

		QMessageBox msgBox;
		QString info = QString("The pixel width is %1 pix").arg(pixel_x) + "\n" +QString("The pixel hight is %1 pix").arg(pixel_y) +"\n"+QString("The pixel area is %1 pix").arg(pixel_area) +"\n"+ "\n" + QString("The pixel factor is %2 mm/pix").arg(calib_factor) + "\n" + "\n" + QString("The real width is %1 mm").arg(real_x) + "\n" + QString("The real hight is %1 mm").arg(real_y) + "\n" + QString("The real area is %1 mm2").arg(real_area) + "\n";
		msgBox.setWindowTitle("Regional Measurement Result");
		msgBox.setText(info);
		msgBox.exec();
		measure_point.clear();
	}
	
	
}


void MainWindow::mesure_start(int key)
{
	setCursor(Qt::CrossCursor);
	if (key == Qt::Key_Escape) { setCursor(Qt::ArrowCursor); Measure_start = false; measure_point.clear();}
	if (key==Qt::Key_Return)
	{
		ShowMeasureRes(measure_point, calib_factor);
		measure_point.clear();
	}

}

void MainWindow::keyPressEvent(QKeyEvent *event_key)
{
	if (event_key->key() == Qt::Key_Return&& Measure_start)
	{
		mesure_start(Qt::Key_Return);
	}
	//if (event_key->key() == Qt::Key_Space && Measure_start)
	//{
	//	mesure_start(Qt::Key_Space);
	//}
	if (event_key->key() == Qt::Key_Escape && Measure_start)
	{
		mesure_start(Qt::Key_Escape);
	}

}


void MainWindow::domeasure() 
{
	Measure_start = true;
	measure_point.clear();

	ImgWin* win_cur = getCurrent();
	connect(win_cur, SIGNAL(mousePressInfo(QPoint)), this, SLOT(imgMousePressInfo(QPoint)), Qt::UniqueConnection);

	QString all_title= win_cur->windowTitle();
	QStringList titles = all_title.split("/");
	QString pic_title = titles.last();

	if (calib_factor == 0) 
	{
		QString file_res_calib;
		file_res_calib = QFileDialog::getOpenFileName(this, "calibration result", "",
				"TXT Files (*.txt);;Any Files (*.*)");
	
		QDir dir = QDir::current();
		QFile file(file_res_calib);
		if (!file.open(QIODevice::ReadOnly))
		{
			QMessageBox::critical(this, "error", "OPEN FILE FAILED!!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
			return;
		}
		QTextStream * out = new QTextStream(&file);//�ı���
		QStringList tempOption = out->readAll().split("\n");//ÿ����\n����
		calib_factor_avg = 0;
		calib_factor = 0;
		bool m = false;
		for (int i = 0; i<tempOption.count(); i++)
		{

			QString a = tempOption.at(i);
			QStringList tempbar = a.split(",");
			if (tempbar[0] == pic_title) { calib_factor_avg = tempbar.last().toFloat(); m = true; break; }
			calib_factor_avg += tempbar.last().toFloat();
		}
		if (m == true)  
			calib_factor = calib_factor_avg; 
		else
			calib_factor = calib_factor_avg / tempOption.count();
	
		file.close();//������ɺ�ǵùر��ļ�
	}
	setCursor(Qt::CrossCursor);

	//connect(win_cur, SIGNAL(mousePressInfo(QPoint)), this, SLOT(imgMousePressInfo(QPoint)));

}


/******************************************************************************
 * removeWindowListItem(QAction*): Remove the QAction from the window list.
 * Slot function.
 * Signalers: ImgWin->closing(QAction*)
 * Remove the QAction from the window menu when the window closes.
 *****************************************************************************/
void MainWindow::removeWindowListItem(QAction* act)
{
    ui->menuWindow->removeAction(act);
}


/******************************************************************************
 * imgMouseInfo(QPoint): Display mouse info.
 * Slot function.
 * Signalers: ImgWin->mouseOverInfo(QPoint)
 * Display that the mouse is at the given point on the image (not screen).
 *****************************************************************************/
void MainWindow::imgMouseInfo(QPoint p)
{
	//if (enter_press) {
	//	ShowMeasureRes(measure_point, calib_factor);
	//	enter_press = false;
	//	measure_point.clear();
	//}
		
    QImage i = getImage();
    if (i.isNull())
        return;
    QColor c(i.pixel(p));
    QString msg = QString("%1,%2 (%3,%4) [h%5 s%6 v%7]")
            .arg(p.x()).arg(p.y())
            .arg(i.width()).arg(i.height())
            .arg(c.hue()).arg(c.saturation()).arg(c.value());
    ui->statusBar->showMessage(msg);
    QPalette pal = status_color_swatch->palette();
    pal.setColor(status_color_swatch->backgroundRole(), c);
    status_color_swatch->setPalette(pal);
}


void MainWindow::imgMousePressInfo(QPoint p)
{
	measure_point.push_back(p);
}

/******************************************************************************
 * zoomChanged(int): Change the zoom combobox to the current zoom.
 * Slot function.
 * Signalers: zoom_slider->valueChanged(int)
 * Get the zoom value from the slider and set the box to it.
 *****************************************************************************/
void MainWindow::zoomChanged(int s)
{
    zoom_box->setEditText(QString::number(s));
}

/******************************************************************************
 * zoomBoxChanged(int): Change the zoom to the zoom combobox's value.
 * Slot function.
 * Signalers: zoom_box->editTextChanged(int)
 * Get the zoom value from the box and set the window to it.
 *****************************************************************************/
void MainWindow::zoomBoxChanged(QString str)
{
    int n = str.toInt();
    zoom_slider->setValue(n);
}

void MainWindow::on_mdiArea_subWindowActivated(QMdiSubWindow *arg1)
{

}

void MainWindow::neighbor_image_searching()
{
	int num;
	bool isFour, isEight, isOther;
	QDialog* a = new QDialog(this);
	Ui::LocalStitchingDialog* LocalStitchingSetting = new Ui::LocalStitchingDialog;// new Ui::Dialog;
	LocalStitchingSetting->setupUi(a);
	//����Ĭ�ϲ���
	LocalStitchingSetting->radioButton->setChecked(true);
	a->exec();
	//ѡ�����
	isFour = LocalStitchingSetting->radioButton->isChecked();
	isEight = LocalStitchingSetting->radioButton_2->isChecked();
	isOther = LocalStitchingSetting->radioButton_3->isChecked();
	if (isFour) { num = 4; }
	if (isEight) { num = 8; }
	if (isOther) { num = 16; }


	QString selected_img = QFileDialog::getOpenFileName(this, "Select the image for neighbor searching", "",
		"Image Files (*.png *.jpg *.bmp *.gif);;Any Files (*.*)");
	if (selected_img == NULL) { QMessageBox::critical(this, "error", "Select an image for neighbor searching!!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes); return; }

	vector<char>whole_name;
	vector<char>imgDir_char;
	vector<char>imgName_char;
	vector<int>mark;
	string std_str = selected_img.toLocal8Bit().data();

	for (int i = 0; i < std_str.size(); i++)
	{
		whole_name.push_back(std_str[i]);
		if (std_str[i] == '/')
			mark.push_back(i);      //���ͼƬĿ¼�ַ�����б�ܵ�λ��
	}
	for (int i = 0; i <= mark.back(); i++)
	{
		imgDir_char.push_back(whole_name[i]);   //�õ���ѡͼƬ��Ŀ¼����ʽΪ "C:/Desktop/stitching/"
	}
	for (int i = mark.back() + 1; i < whole_name.size(); i++)
	{
		imgName_char.push_back(whole_name[i]);  //�õ���ѡͼƬ�����ƣ���ʽΪ "DSC0936.JPG"
	}
	string img_dir(imgDir_char.begin(), imgDir_char.end());
	string img_name(imgName_char.begin(), imgName_char.end());  //ת��Ϊstring����

	QString coordinates_file = QFileDialog::getOpenFileName(this, "Coordinate path", "", //�򿪰���ͼ������λ�ù�ϵ��csv�ļ�
		" Any Files (*.csv)");
	if (coordinates_file == NULL)
	{
		QMessageBox::critical(this, "error", "Select the corresponding csv file!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes); return;
	}

	string temp = coordinates_file.toLocal8Bit().data();
	const char* coordinates_csv_file = temp.c_str(); //��csv�ļ���ת��Ϊconst char*�����Ա��ȡ
	/*CvMLData mlData;
	mlData.read_csv(coordinates_csv_file);
	cv::Mat data = cv::Mat(mlData.get_values(), true);*/

	ifstream inFile(coordinates_csv_file);
	string lineStr;
	vector<vector<string>>data;
	while (getline(inFile, lineStr))
	{
		stringstream ss(lineStr);
		string str;
		vector<string>lineArray;
		while (getline(ss, str, ','))
			lineArray.push_back(str);

		data.push_back(lineArray);

	}
	if (data[0].size() < 5)  //��Ҫ�̶���ʽ��csv�ļ�����ֹ��������쳣
	{
		QMessageBox::critical(NULL, "error", "Wrong csv file!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes); return;
	}

	int selected_img_index = INT_MAX;
	int i = 1;
	vector<double>x;
	vector<double>y;
	vector<double>dist;
	vector<double>dist_temp;
	while (i < data.size())
	{
		const char* x_temp_char = data[i][3].c_str();
		double x_fromString = atof(x_temp_char);
		x.push_back(x_fromString);
		const char* y_temp_char = data[i][4].c_str();
		double y_fromString = atof(y_temp_char);
		y.push_back(y_fromString);  //��¼ͼ�����е�����
		//for (int i = 1; i < 20; i++) //
		//{
		//	string s =data[i][1];//
		//}//

		if (img_name == data[i][1]) //������ѡͼ������������ѡͼ����cvs�ļ��е���һ��
		{
			selected_img_index = i;   //��¼��ѡͼ������
		}
		i++;
	}
	//����ڶ�Ӧcsv�ļ����Ҳ�����ѡͼ�������������ʾ
	if (selected_img_index == INT_MAX) { QMessageBox::critical(NULL, "error", "The corresponding image was not found in the .cvs file!!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes); return; }
	if (x.size() <= num) { QMessageBox::critical(NULL, "error", "Images under the directory are not enough!!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes); return; }

	const char* selected_x_temp_char = data[selected_img_index][3].c_str();
	double selected_x_fromString = atof(selected_x_temp_char);
	const char* selected_y_temp_char = data[selected_img_index][4].c_str();
	double selected_y_fromString = atof(selected_y_temp_char);
	double selected_img_x = selected_x_fromString;
	double selected_img_y = selected_y_fromString; //�����ֲ�����������ѡͼ������꣬���ڱ�ʾ

	for (int i = 0; i < x.size(); i++)
	{
		double C = sin(y[i])*sin(selected_img_y)*cos(x[i] - selected_img_x) + cos(y[i])*cos(selected_img_y);
		double Distance = 6371004 * acos(C)*PI / 180; //��γ��ת��Ϊ����
		//double Distance = sqrt((x[i] - selected_img_x)*(x[i] - selected_img_x) + (y[i] - selected_img_y)*(y[i] - selected_img_y));
		dist.push_back(Distance);    //��ÿ��ͼ������ѡͼ����������洢����
	}

	dist[selected_img_index - 1] = INT_MAX;  //����ѡͼ���������ľ�������Ϊ���ֵ������ѡ������

	for (int i = 0; i < dist.size(); i++)
	{
		dist_temp.push_back(dist[i]);  //������ǰ��ͼ���������洢��һ���м�����У����ں�������
	}
	sort(dist.begin(), dist.end());  //��ͼ����������������
	int j = 0;
	vector<int>searched_img_index;
	while (j < num)       //���������4����ͼ�񣬿�������Ϊ��qt��̬ѡ������4������8����
	{
		for (int i = 0; i < dist.size(); i++) //����̵�4/8��������ԭ�����������αȶԣ��õ����������4/8��ͼ�������
		{
			if (dist_temp[i] == dist[j])
			{
				searched_img_index.push_back(i);
				dist_temp[i] = INT_MAX;
				break;
			}
		}
		j++;
	}
	vector<string> searched_img_name_std;
	for (int i = 0; i < num; i++)
	{
		int index = searched_img_index[i] + 1;
		searched_img_name_std.push_back(data[index][1]); //����ͼ�������õ�ͼ������
	}
	QStringList searched_img_name;
	for (int i = 0; i < num; i++)
	{
		searched_img_name_std[i] = img_dir + searched_img_name_std[i]; //��ͼ��������Ŀ¼���������������õ�ͼ���ڼ�����е���������
	}
	for (int i = 0; i < searched_img_name_std.size(); i++)
	{
		searched_img_name.push_back(QString::fromStdString(searched_img_name_std[i]));
	}


	if (selected_img != "")
	{
		QImageReader *reader = new QImageReader(selected_img);//AAAA
		QImage img = reader->read();
		if (!img.isNull())
		{
			ImgWin* win = new ImgWin;
			win->setImage(img);
			win->setWindowTitle(selected_img);
			win->setReader(reader);

			// Display the image window
			QMdiSubWindow* subwin = ui->mdiArea->addSubWindow(win);
			subwin->showMaximized();

			// Add a item to the window menu, and give it to the imgwin to keep track of
			win->setMenuItem(ui->menuWindow->addAction(selected_img, subwin, SLOT(setFocus())));
			connect(win, SIGNAL(closing(QAction*)), this, SLOT(removeWindowListItem(QAction*)));

			// Mouse info
			connect(win, SIGNAL(mouseOverInfo(QPoint)), this, SLOT(imgMouseInfo(QPoint)), Qt::UniqueConnection);//, Qt::UniqueConnection
		}
	}

	for (int i = 0; i < num; i++)
	{
		if (searched_img_name[i] != "")
		{
			QImageReader *reader = new QImageReader(searched_img_name[i]);//AAAA
			QImage img = reader->read();
			if (!img.isNull())
			{
				ImgWin* win = new ImgWin;
				win->setImage(img);
				win->setWindowTitle(searched_img_name[i]);
				win->setReader(reader);

				// Display the image window
				QMdiSubWindow* subwin = ui->mdiArea->addSubWindow(win);
				subwin->showMaximized();

				// Add a item to the window menu, and give it to the imgwin to keep track of
				win->setMenuItem(ui->menuWindow->addAction(searched_img_name[i], subwin, SLOT(setFocus())));
				connect(win, SIGNAL(closing(QAction*)), this, SLOT(removeWindowListItem(QAction*)));

				// Mouse info
				connect(win, SIGNAL(mouseOverInfo(QPoint)), this, SLOT(imgMouseInfo(QPoint)), Qt::UniqueConnection);//, Qt::UniqueConnection
			}
		}
	}

	fileNames.clear();

	fileNames.push_back(std_str);
	for (int i = 0; i < searched_img_name.length(); i++) {
		fileNames.push_back(searched_img_name[i].toStdString());
	}
	
	NumImg = fileNames.size();

	//��������м����ռ�õĿռ�
	whole_name.clear();
	imgDir_char.clear();
	imgName_char.clear();
	mark.clear();
	data.clear();
	x.clear();
	y.clear();
	dist.clear();
	dist_temp.clear();
	searched_img_index.clear();
	searched_img_name_std.clear();

	ui->actionParameter_setting->setEnabled(true);
	ui->actionMeasure->setEnabled(true);

	
}

void MainWindow::generating_data()
{
	QString dataPath;
	string picturePath;

	//�õ�ͼƬ�ļ��е�ַ E:\study_program\20181126\getpicdata\picdata1
    picturePath = file[0].toLocal8Bit();
	for (int i = picturePath.length() - 1; picturePath[i] != '/'; i--) {
		picturePath.erase(picturePath.end() - 1);
	}
	picturePath.erase(picturePath.end() - 1);

	//�õ��洢�ɻ���̬���ݵ�.txt�ļ�·��
	dataPath = QFileDialog::getOpenFileName(this, "data", "",
		"TXT Files (*.txt);;Any Files (*.*)");

    //�洢ͼƬ��Ϣ�ı���
	pictureType pictureInfo;

	//�洢�ɻ���̬���ݵ�����
	vector<vector<string>> data;

	//��ȡ���и�ʽΪjpg���ļ�
	const string format = ".jpg";
	

	//��ȡͼ����Ϣ
	if (GetAllFormatFiles(picturePath, pictureInfo, format) == -1)
	{
		cout << "error:can't find *.jpg files!" << endl;
	};

    //�õ��ɻ���̬
	if (getData1(dataPath.toStdString(), data, pictureInfo.pictureNum) == -1)
	{
		cout << "error:can't open the file!" << endl;
	};
	
	//string newDataPath;
	string newDataPath = picturePath+"//data.csv";
	
	//�����ɵ��ļ�
	if (newDataWrite(newDataPath, data, pictureInfo) == -1)
	{
		cout << "error:create file failed!" << endl;
	}

	//��ʾ�����ɵ��ļ�
	QString ext_para_path = QString::fromStdString(newDataPath) ;
	Calibres *calibresDilog1 = new Calibres;
	QStringList header;
	header << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "10" << "11" << "12" << "13";
	calibresDilog1->show_excel(ext_para_path, header, "data", 100, 16);	
}