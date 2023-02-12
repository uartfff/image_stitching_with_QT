/******************************************************************************
 * imgabout.h
 * Header file for the basic image info dialog. See the imgabout.cpp file for
 * more information.
 *****************************************************************************/
#ifndef IMGABOUT_H
#define IMGABOUT_H

#include <QDialog>
#include "imgwin.h"

namespace Ui {
    class imgAbout;
}

class imgAbout : public QDialog
{
    Q_OBJECT

public:
    explicit imgAbout(QWidget *parent = 0);
    ~imgAbout();
    void setup(ImgWin *);

private:
    Ui::imgAbout *ui;
};

#endif // IMGABOUT_H
