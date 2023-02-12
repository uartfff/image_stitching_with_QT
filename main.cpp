/******************************************************************************
 * main.cpp
 * The base of the application.
 * Author: Yao Guo.
 * Date of first commit: 10 Apr, 2019.
 * Created by Qt Creator, no changes made.
 * Known issues: None
 *****************************************************************************/
#include <QApplication>
#include "mainwindow.h"
#include <QTextCodec>

/******************************************************************************
 * main(int argc, char *argv[]): Start the application.
 *****************************************************************************/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
