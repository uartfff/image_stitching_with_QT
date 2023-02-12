/******************************************************************************
 * imgwin.h
 * Header file for the image viewer window. See the imgwin.cpp file for
 * more information.
 *****************************************************************************/

#ifndef IMGWIN_H
#define IMGWIN_H

#include <QScrollArea>
#include <QImageReader>
#include <QMouseEvent>

namespace Ui {
    class ImageWindow;
}

class ImgWin : public QScrollArea
{
    Q_OBJECT
public:
    explicit ImgWin(QWidget *parent = 0);
    ~ImgWin();

    QImage getImage()
    {
        return image;
    }

    void setImage(QImage);

    QRect getSelection();

    int getScale() const
    {
        return scaleFactor * 100;
    }

    QImageReader* getReader()
    {
        return reader;
    }
    void setReader(QImageReader *inreader)
    {
        reader = inreader;
    }

	void MousePress(QMouseEvent *event);

signals:
    void closing(QAction*);
    void scaleChanged(int);
    void mouseOverInfo(QPoint);
	void mousePressInfo(QPoint);

public slots:
    void setScale(int);

    void setMenuItem(QAction* a)
    {
        menu_item = a;
    }

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void labelMouseInfo(QPoint p)
    {
        emit mouseOverInfo(p / scaleFactor);
    }
	void labelMousePressInfo(QPoint p)
	{
		emit mousePressInfo(p / scaleFactor);
	}

private:
    Ui::ImageWindow *ui;
    QAction *menu_item;
    QImageReader *reader;
    QImage image;
    float scaleFactor;
	QMouseEvent *event;
};

#endif // IMGWIN_H
