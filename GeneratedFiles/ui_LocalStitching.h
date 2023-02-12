/********************************************************************************
** Form generated from reading UI file 'LocalStitching.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCALSTITCHING_H
#define UI_LOCALSTITCHING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LocalStitchingDialog
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;

    void setupUi(QDialog *LocalStitchingDialog)
    {
        if (LocalStitchingDialog->objectName().isEmpty())
            LocalStitchingDialog->setObjectName(QStringLiteral("LocalStitchingDialog"));
        LocalStitchingDialog->resize(459, 366);
        buttonBox = new QDialogButtonBox(LocalStitchingDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(90, 270, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(LocalStitchingDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 391, 221));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 341, 181));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(layoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(layoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(layoutWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout->addWidget(radioButton_3);


        retranslateUi(LocalStitchingDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), LocalStitchingDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LocalStitchingDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LocalStitchingDialog);
    } // setupUi

    void retranslateUi(QDialog *LocalStitchingDialog)
    {
        LocalStitchingDialog->setWindowTitle(QApplication::translate("LocalStitchingDialog", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("LocalStitchingDialog", "\351\202\273\345\237\237\351\200\211\346\213\251", Q_NULLPTR));
        radioButton->setText(QApplication::translate("LocalStitchingDialog", "\345\233\233\351\202\273\345\237\237", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("LocalStitchingDialog", "\345\205\253\351\202\273\345\237\237", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("LocalStitchingDialog", "\345\215\201\345\205\255\351\202\273\345\237\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LocalStitchingDialog: public Ui_LocalStitchingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCALSTITCHING_H
