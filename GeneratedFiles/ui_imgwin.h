/********************************************************************************
** Form generated from reading UI file 'imgwin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGWIN_H
#define UI_IMGWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>
#include "imageeditlabel.h"

QT_BEGIN_NAMESPACE

class Ui_ImageWindow
{
public:
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    ImageEditLabel *pictureLabel;

    void setupUi(QScrollArea *ImageWindow)
    {
        if (ImageWindow->objectName().isEmpty())
            ImageWindow->setObjectName(QStringLiteral("ImageWindow"));
        ImageWindow->resize(71, 71);
        ImageWindow->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(31, 27, 7, 15));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pictureLabel = new ImageEditLabel(scrollAreaWidgetContents);
        pictureLabel->setObjectName(QStringLiteral("pictureLabel"));
        pictureLabel->setMouseTracking(true);
        pictureLabel->setFrameShape(QFrame::StyledPanel);
        pictureLabel->setFrameShadow(QFrame::Sunken);
        pictureLabel->setLineWidth(2);
        pictureLabel->setScaledContents(true);

        horizontalLayout->addWidget(pictureLabel);

        ImageWindow->setWidget(scrollAreaWidgetContents);

        retranslateUi(ImageWindow);

        QMetaObject::connectSlotsByName(ImageWindow);
    } // setupUi

    void retranslateUi(QScrollArea *ImageWindow)
    {
        pictureLabel->setText(QString());
        Q_UNUSED(ImageWindow);
    } // retranslateUi

};

namespace Ui {
    class ImageWindow: public Ui_ImageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGWIN_H
