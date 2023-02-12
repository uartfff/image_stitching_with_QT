/******************************************************************************
 * mainwindow.h
 * Header file for mainwindow.cpp, where you can find more details about the
 * purpose of these two files.
 *****************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressDialog>
#include <QTimer>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QVector>
#include <vector>
#include <string>

class QMdiSubWindow;
class QLabel;
class QSlider;
class QComboBox;
class ImgWin;
using namespace std;

namespace Ui {
    class MainWindow;
    class ImgResizeDialog;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
	bool state;
	bool state1;
    bool aux_info1,aux_info2;
    bool extra_way1,extra_way2, is_origin_Resolving;
	int NumImg;
	QStringList file;
	QString Coordinate_path;
	double Multiple;
	int multiple_bends = 2;
	vector<string> fileNames;
	//vector<string> a;
	QProgressDialog* progDlg;
	QTimer* timer;
	double currentValue = 0;

	//QImage Mat2QImage(const cv::Mat& mat);

signals:
    void imageEditable(bool);

public slots:
    // File operations
    void doOpen();
    void doSave();
    // Image manipulations
    void doResize();
	void parameter_setting();
	void start();
	void stitching();
	//measure
	void domeasure();

    // Menu disabling functions
    void doChangeImage(QMdiSubWindow*);
    void removeWindowListItem(QAction* act);
    // Dialogs
    void doFillWindow();
    void doInfo();
    void doAbout();
    // Mouseover info
    void imgMouseInfo(QPoint);
	void imgMousePressInfo(QPoint p);


    void zoomChanged(int);
    void zoomBoxChanged(QString);

    void on_mdiArea_subWindowActivated(QMdiSubWindow *arg1);
	void updateProgressDialog();

	void neighbor_image_searching();
	
	void generating_data();


public:
	//void mousePressEvent(QMouseEvent *event);        //µ¥»÷
	void keyPressEvent(QKeyEvent *event_key);
	void mesure_start(int key);


	void ShowMeasureRes(QVector<QPoint> measure_point,float calib_factor);
	QMouseEvent *event;
	QKeyEvent *event_key;

    ImgWin* getCurrent();
    QImage getImage();
    void setImage(QImage p);

    Ui::MainWindow *ui;
    QSlider *zoom_slider;
    QComboBox *zoom_box;
    QWidget *status_color_swatch;
};

#endif // MAINWINDOW_H
