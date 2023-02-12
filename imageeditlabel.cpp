/******************************************************************************
 * imgeditlabel.cpp
 * The label that holds the image and keeps track of selections and mouse-over
 * information.
 * Author: Samuel Harrington
 * Date of first commit: 10 October, 2011
 * Known Issues: None.
 *****************************************************************************/

#include "imageeditlabel.h"
#include <QRubberBand>

/******************************************************************************
 * ImageEditLabel(QWidget *parent): Create this label and the rubber band
 * selector to be used later.
 *****************************************************************************/
ImageEditLabel::ImageEditLabel(QWidget *parent) :
    QLabel(parent), rubber(new QRubberBand(QRubberBand::Rectangle, this))
{
    rubber->setMouseTracking(true);
}

/******************************************************************************
 * mousePressEvent(QMouseEvent *ev): Handle mouse presses and start the
 * selection creation.
 *****************************************************************************/
void ImageEditLabel::mousePressEvent(QMouseEvent *ev)
{
    dragStart = ev->pos();
    rubber->setGeometry(QRect(dragStart, QSize()));
    rubber->show();
}

/******************************************************************************
 * mouseMoveEvent(QMouseEvent *ev): Handle mouse movement by resizing the
 * selection and by sending information about where the mouse is currently.
 *****************************************************************************/
void ImageEditLabel::mouseMoveEvent(QMouseEvent *ev)
{
    if (ev->buttons() & Qt::LeftButton)
        rubber->setGeometry(QRect(dragStart,ev->pos()).normalized());
    emit mouseOverInfo(ev->pos());
}

void ImageEditLabel::mouseReleaseEvent(QMouseEvent *ev)
{
	QPoint a;
	if (ev->button() == Qt::RightButton)
	{
		a = dragStart;
		emit mousePressInfo(a);
	}
}

