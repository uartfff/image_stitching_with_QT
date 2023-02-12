/********************************************************************************
** Form generated from reading UI file 'ParameterDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETERDIALOG_H
#define UI_PARAMETERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *groupBox;
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QRadioButton *noncoordinates;
    QRadioButton *coordinates;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDoubleSpinBox *down;
    QCheckBox *checkBox_6;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *min_multiple;
    QLabel *label_6;
    QLabel *max_multiple;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(553, 377);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 511, 351));
        groupBox->setStyleSheet(QStringLiteral("font: 75 12pt \"Agency FB\";"));
        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(300, 300, 201, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget_3 = new QWidget(groupBox);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(100, 187, 241, 91));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        noncoordinates = new QRadioButton(verticalLayoutWidget_3);
        noncoordinates->setObjectName(QStringLiteral("noncoordinates"));

        verticalLayout_3->addWidget(noncoordinates);

        coordinates = new QRadioButton(verticalLayoutWidget_3);
        coordinates->setObjectName(QStringLiteral("coordinates"));

        verticalLayout_3->addWidget(coordinates);

        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(100, 30, 241, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        down = new QDoubleSpinBox(verticalLayoutWidget);
        down->setObjectName(QStringLiteral("down"));

        verticalLayout->addWidget(down);

        checkBox_6 = new QCheckBox(verticalLayoutWidget);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));

        verticalLayout->addWidget(checkBox_6);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 130, 151, 20));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(250, 130, 61, 21));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        min_multiple = new QLabel(horizontalLayoutWidget);
        min_multiple->setObjectName(QStringLiteral("min_multiple"));

        horizontalLayout->addWidget(min_multiple);

        label_6 = new QLabel(horizontalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);

        max_multiple = new QLabel(horizontalLayoutWidget);
        max_multiple->setObjectName(QStringLiteral("max_multiple"));

        horizontalLayout->addWidget(max_multiple);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Dialog", "\346\213\274\346\216\245\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-weight:600;\">\345\235\220\346\240\207\344\277\241\346\201\257\357\274\232</span></p></body></html>", Q_NULLPTR));
        noncoordinates->setText(QApplication::translate("Dialog", "\346\227\240\345\235\220\346\240\207", Q_NULLPTR));
        coordinates->setText(QApplication::translate("Dialog", "\346\234\211\345\235\220\346\240\207", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\351\231\215\351\207\207\346\240\267\345\200\215\346\225\260\357\274\232</span></p></body></html>", Q_NULLPTR));
        checkBox_6->setText(QApplication::translate("Dialog", "\345\216\237\345\247\213\345\210\206\350\276\250\347\216\207\347\273\223\346\236\234", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600; text-decoration: underline;\">\345\273\272\350\256\256\347\232\204\351\231\215\351\207\207\346\240\267\345\200\215\346\225\260\357\274\232</span></p></body></html>", Q_NULLPTR));
        min_multiple->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600; text-decoration: underline;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600; text-decoration: underline;\">\350\207\263</span></p></body></html>", Q_NULLPTR));
        max_multiple->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600; text-decoration: underline;\">TextLabel</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERDIALOG_H
