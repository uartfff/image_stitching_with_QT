/******************************************************************************
 * imgwin.cpp
 * Create a window to display images.
 * Author: Yao Guo
 * This window is configured to allow scrolling if the image is bigger than the
 * window's view area, while allowing the image to be resized.
 * Date of first commit: 9 Apr, 2019
 * Known issues: None
 *****************************************************************************/
#include "ui_imgwin.h"
#include "imgwin.h"
#include <QCloseEvent>

/******************************************************************************
 * ImgWin(QWidget*): Creates the ImgWin class
 * Creates the image window, passing the parent to QScrollArea, and
 * initializing the ui.
 *****************************************************************************/
ImgWin::ImgWin(QWidget *parent) :
    QScrollArea(parent), ui(new Ui::ImageWindow), scaleFactor(1.0)
{

    ui->setupUi(this);
    connect(ui->pictureLabel, SIGNAL(mouseOverInfo(QPoint)), SLOT(labelMouseInfo(QPoint)));
	connect(ui->pictureLabel, SIGNAL(mousePressInfo(QPoint)), SLOT(labelMousePressInfo(QPoint)));
}

/******************************************************************************
 * ~ImgWin(): Destroys the ImgWin class
 * Destroys the image window, deleting the ui.
 *****************************************************************************/
ImgWin::~ImgWin()
{
    delete ui;
    delete reader;
}

/******************************************************************************
 * setImage(QImage): Set the image
 * Public function.
 * Sets the current image in the pictureLabel.
 *****************************************************************************/
void ImgWin::setImage(QImage i)
{
    image = i;
    ui->pictureLabel->setPixmap(QPixmap::fromImage(image));
    ui->scrollAreaWidgetContents->resize(image.size() * scaleFactor);
    ui->pictureLabel->setImgSelection(QRect(0,0,0,0));
}

/******************************************************************************
 * QRect setSelection(QPixmap): Get the mouse selection of the image
 * Public function.
 * Get the selection of the user on the pictureLabel.
 *****************************************************************************/
QRect ImgWin::getSelection()
{
    QRect sel = ui->pictureLabel->getImgSelection();
    return QRect(sel.topLeft() / scaleFactor, sel.size() / scaleFactor);
}

/******************************************************************************
 * closeEvent(QCloseEvent*): Event handler when the window is closed.
 * Overridden protected function.
 * When the window is closed, let the world know that the menu_item is no
 * longer valid.
 *****************************************************************************/
void ImgWin::closeEvent(QCloseEvent *event)
{
    emit closing(menu_item);
    event->accept();
}

/******************************************************************************
 * setScale(int): Change the image zoom.
 * Public function.
 * Set the scale factor for the zoom, and resize the view and selection.
 *****************************************************************************/
void ImgWin::setScale(int factor)
{
    QRect sel = getSelection();
    scaleFactor = factor / 100.0;
    ui->scrollAreaWidgetContents->resize(ui->pictureLabel->pixmap()->size() * scaleFactor);
    ui->pictureLabel->setImgSelection(QRect(sel.topLeft() * scaleFactor, sel.size() * scaleFactor));
    emit scaleChanged(scaleFactor * 100);
}

void ImgWin::MousePress(QMouseEvent *event)
{
	emit mousePressEvent(event);
}
