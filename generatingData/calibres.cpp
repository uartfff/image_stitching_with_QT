/******************************************************************************
* imgabout.cpp
* Create a simple dialog that displays basic information about the current
* image.
* Author: Yao Guo
* Date of first commit: 9 Apr, 2019
* Known Issues: None.
*****************************************************************************/
#include "calibres.h"
#include "ui_CalibRes.h"
#include <QTableWidget>
#include <QTextStream>
#include <QDir>

// Default constructor; created by Qt Designer.
Calibres::Calibres(QWidget *parent) :
	QDialog(parent)
{
	/*setupUi(this);*/
}

// Default destructor; created by Qt Designer.
Calibres::~Calibres()
{
	delete ui;
}

/******************************************************************************
* setup(ImgWin*): Set the correct values for the strings based on the target
* window.
* This should replace all of the default text in the about window with
* accurate information about the current active image.
* Called from: MainWindow::doInfo()
*****************************************************************************/
void Calibres::show_excel(QString file_name, QStringList header,QString window_title,int rows,int cols)
{
	QTableWidget *tableWidget = new QTableWidget(rows, cols);
	tableWidget->setWindowTitle(window_title);
	tableWidget->resize(500, 200); //���ñ���
	tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//����ѡ����ɫ
	tableWidget->setStyleSheet("selection-background-color:pink");
	//�Զ��������һ�еĿ���ʹ���ͱ�����ұ߽����
	//tableWidget->horizontalHeader()->setStretchLastSection(true);
	// ѡ�е�����Ԫ��
	tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
	//QStringList header;
	if (header.size() == NULL) { header << "A" << "B" << "C"; }
	tableWidget->setHorizontalHeaderLabels(header);
	QDir dir = QDir::current();
	QFile file(dir.filePath(file_name));
	if (!file.open(QIODevice::ReadOnly)) 
	{
		QMessageBox::critical(NULL, "error", "OPEN FILE FAILED!!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}
	QTextStream * out = new QTextStream(&file);//�ı���
	QStringList tempOption = out->readAll().split("\n");//ÿ����\n����
	for (int i = 0; i < rows && i<tempOption.count(); i++)
	{
		QString a=tempOption.at(i);
		QStringList tempbar = a.split(",");
		for (int j = 0; j < cols && j<tempbar.size(); j++)
		{ 
			tableWidget->setItem(i, j, new QTableWidgetItem(tempbar[j]));
		}

	}
	file.close();//������ɺ�ǵùر��ļ�
	tableWidget->show();
}
