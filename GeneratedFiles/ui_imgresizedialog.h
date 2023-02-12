/********************************************************************************
** Form generated from reading UI file 'imgresizedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGRESIZEDIALOG_H
#define UI_IMGRESIZEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ImgResizeDialog
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *widthSpin;
    QLabel *label_2;
    QSpinBox *heightSpin;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ImgResizeDialog)
    {
        if (ImgResizeDialog->objectName().isEmpty())
            ImgResizeDialog->setObjectName(QStringLiteral("ImgResizeDialog"));
        ImgResizeDialog->setWindowModality(Qt::ApplicationModal);
        ImgResizeDialog->resize(174, 93);
        formLayout = new QFormLayout(ImgResizeDialog);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(ImgResizeDialog);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        widthSpin = new QSpinBox(ImgResizeDialog);
        widthSpin->setObjectName(QStringLiteral("widthSpin"));
        widthSpin->setMinimum(1);
        widthSpin->setMaximum(1000000);
        widthSpin->setSingleStep(10);

        formLayout->setWidget(0, QFormLayout::FieldRole, widthSpin);

        label_2 = new QLabel(ImgResizeDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        heightSpin = new QSpinBox(ImgResizeDialog);
        heightSpin->setObjectName(QStringLiteral("heightSpin"));
        heightSpin->setMinimum(1);
        heightSpin->setMaximum(1000000);
        heightSpin->setSingleStep(10);

        formLayout->setWidget(1, QFormLayout::FieldRole, heightSpin);

        buttonBox = new QDialogButtonBox(ImgResizeDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(2, QFormLayout::SpanningRole, buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(widthSpin);
        label_2->setBuddy(heightSpin);
#endif // QT_NO_SHORTCUT

        retranslateUi(ImgResizeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ImgResizeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ImgResizeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ImgResizeDialog);
    } // setupUi

    void retranslateUi(QDialog *ImgResizeDialog)
    {
        ImgResizeDialog->setWindowTitle(QApplication::translate("ImgResizeDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ImgResizeDialog", "&Width", Q_NULLPTR));
        label_2->setText(QApplication::translate("ImgResizeDialog", "&Height", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ImgResizeDialog: public Ui_ImgResizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGRESIZEDIALOG_H
