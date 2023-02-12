/********************************************************************************
** Form generated from reading UI file 'imgabout.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGABOUT_H
#define UI_IMGABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_imgAbout
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *fname;
    QLabel *label_2;
    QLabel *ftype;
    QLabel *label_3;
    QLabel *fsize;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *imgAbout)
    {
        if (imgAbout->objectName().isEmpty())
            imgAbout->setObjectName(QStringLiteral("imgAbout"));
        imgAbout->resize(174, 98);
        formLayout = new QFormLayout(imgAbout);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(imgAbout);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        fname = new QLabel(imgAbout);
        fname->setObjectName(QStringLiteral("fname"));

        formLayout->setWidget(0, QFormLayout::FieldRole, fname);

        label_2 = new QLabel(imgAbout);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        ftype = new QLabel(imgAbout);
        ftype->setObjectName(QStringLiteral("ftype"));

        formLayout->setWidget(1, QFormLayout::FieldRole, ftype);

        label_3 = new QLabel(imgAbout);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        fsize = new QLabel(imgAbout);
        fsize->setObjectName(QStringLiteral("fsize"));

        formLayout->setWidget(2, QFormLayout::FieldRole, fsize);

        buttonBox = new QDialogButtonBox(imgAbout);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        formLayout->setWidget(3, QFormLayout::SpanningRole, buttonBox);


        retranslateUi(imgAbout);
        QObject::connect(buttonBox, SIGNAL(accepted()), imgAbout, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), imgAbout, SLOT(reject()));

        QMetaObject::connectSlotsByName(imgAbout);
    } // setupUi

    void retranslateUi(QDialog *imgAbout)
    {
        imgAbout->setWindowTitle(QApplication::translate("imgAbout", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("imgAbout", "File Name:", Q_NULLPTR));
        fname->setText(QApplication::translate("imgAbout", "[Untitled]", Q_NULLPTR));
        label_2->setText(QApplication::translate("imgAbout", "File Type:", Q_NULLPTR));
        ftype->setText(QApplication::translate("imgAbout", "[Unspecified]", Q_NULLPTR));
        label_3->setText(QApplication::translate("imgAbout", "Dimensions:", Q_NULLPTR));
        fsize->setText(QApplication::translate("imgAbout", "[No size]", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class imgAbout: public Ui_imgAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGABOUT_H
