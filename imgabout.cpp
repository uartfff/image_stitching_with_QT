/******************************************************************************
 * imgabout.cpp
 * Create a simple dialog that displays basic information about the current
 * image.
 * Author: Christopher Jensen
 * Date of first commit: 10 October, 2011
 * Known Issues: None.
 *****************************************************************************/
#include "imgabout.h"
#include "ui_imgabout.h"
#include <QImageReader>

// Default constructor; created by Qt Designer.
imgAbout::imgAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::imgAbout)
{
    ui->setupUi(this);
}

// Default destructor; created by Qt Designer.
imgAbout::~imgAbout()
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
void imgAbout::setup(ImgWin *target)
{
    // Use a QImageReader to retrieve some data without getting our hands dirty
    QImageReader* reader = target->getReader();
    ui->fname->setText(reader->fileName());
    ui->ftype->setText(reader->format());

    // Use the image directly to get the dimensions.
    QImage pix = target->getImage();
    int width = pix.size().width();
    int height = pix.size().height();

    // Make the dimensions something we can read easily.
    QString dim = "";
    dim += QString::number(width);
    dim += " x ";
    dim += QString::number(height);
    ui->fsize->setText(dim);
}
