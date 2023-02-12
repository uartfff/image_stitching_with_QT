/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionInvert;
    QAction *actionSharpen;
    QAction *actionSmooth;
    QAction *actionZoom;
    QAction *actionAbout;
    QAction *actionQuit;
    QAction *actionTile;
    QAction *actionCascade;
    QAction *actionSave;
    QAction *actionImage_Info;
    QAction *actionRevert;
    QAction *actionCrop;
    QAction *actionColor_Adjust;
    QAction *actionResize;
    QAction *actionFit_window;
    QAction *actionParameter_setting;
    QAction *actionStart;
    QAction *actionMeasure;
    QAction *actionNeighborStitching;
    QAction *actiongenerating_data;
    QAction *actionNeighbor_stitch;
    QWidget *centralWidget;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuImage;
    QMenu *menuHelp;
    QMenu *menuWindow;
    QMenu *menuMeasure_M;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(964, 603);
        QIcon icon;
        icon.addFile(QStringLiteral("images/bridge.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionInvert = new QAction(MainWindow);
        actionInvert->setObjectName(QStringLiteral("actionInvert"));
        actionInvert->setEnabled(false);
        actionSharpen = new QAction(MainWindow);
        actionSharpen->setObjectName(QStringLiteral("actionSharpen"));
        actionSharpen->setEnabled(false);
        actionSmooth = new QAction(MainWindow);
        actionSmooth->setObjectName(QStringLiteral("actionSmooth"));
        actionSmooth->setEnabled(false);
        actionZoom = new QAction(MainWindow);
        actionZoom->setObjectName(QStringLiteral("actionZoom"));
        actionZoom->setEnabled(false);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout->setMenuRole(QAction::AboutRole);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionQuit->setMenuRole(QAction::QuitRole);
        actionTile = new QAction(MainWindow);
        actionTile->setObjectName(QStringLiteral("actionTile"));
        actionCascade = new QAction(MainWindow);
        actionCascade->setObjectName(QStringLiteral("actionCascade"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setEnabled(false);
        actionImage_Info = new QAction(MainWindow);
        actionImage_Info->setObjectName(QStringLiteral("actionImage_Info"));
        actionImage_Info->setCheckable(true);
        actionImage_Info->setEnabled(false);
        actionRevert = new QAction(MainWindow);
        actionRevert->setObjectName(QStringLiteral("actionRevert"));
        actionRevert->setEnabled(false);
        actionCrop = new QAction(MainWindow);
        actionCrop->setObjectName(QStringLiteral("actionCrop"));
        actionCrop->setEnabled(false);
        actionColor_Adjust = new QAction(MainWindow);
        actionColor_Adjust->setObjectName(QStringLiteral("actionColor_Adjust"));
        actionColor_Adjust->setEnabled(false);
        actionResize = new QAction(MainWindow);
        actionResize->setObjectName(QStringLiteral("actionResize"));
        actionResize->setEnabled(false);
        actionFit_window = new QAction(MainWindow);
        actionFit_window->setObjectName(QStringLiteral("actionFit_window"));
        actionFit_window->setEnabled(false);
        actionParameter_setting = new QAction(MainWindow);
        actionParameter_setting->setObjectName(QStringLiteral("actionParameter_setting"));
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionMeasure = new QAction(MainWindow);
        actionMeasure->setObjectName(QStringLiteral("actionMeasure"));
        actionNeighborStitching = new QAction(MainWindow);
        actionNeighborStitching->setObjectName(QStringLiteral("actionNeighborStitching"));
        actiongenerating_data = new QAction(MainWindow);
        actiongenerating_data->setObjectName(QStringLiteral("actiongenerating_data"));
        actionNeighbor_stitch = new QAction(MainWindow);
        actionNeighbor_stitch->setObjectName(QStringLiteral("actionNeighbor_stitch"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setGeometry(QRect(-10, -10, 1991, 1121));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 964, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuImage = new QMenu(menuBar);
        menuImage->setObjectName(QStringLiteral("menuImage"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuMeasure_M = new QMenu(menuBar);
        menuMeasure_M->setObjectName(QStringLiteral("menuMeasure_M"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setOrientation(Qt::Vertical);
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuImage->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuBar->addAction(menuMeasure_M->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionRevert);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuImage->addAction(actionImage_Info);
        menuImage->addSeparator();
        menuImage->addAction(actionResize);
        menuImage->addSeparator();
        menuImage->addAction(actionFit_window);
        menuImage->addSeparator();
        menuImage->addAction(actionParameter_setting);
        menuImage->addAction(actionStart);
        menuImage->addSeparator();
        menuImage->addAction(actiongenerating_data);
        menuImage->addSeparator();
        menuImage->addAction(actionNeighbor_stitch);
        menuHelp->addAction(actionAbout);
        menuWindow->addAction(actionTile);
        menuWindow->addAction(actionCascade);
        menuWindow->addSeparator();
        menuMeasure_M->addAction(actionMeasure);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionQuit);
        toolBar->addSeparator();
        toolBar->addAction(actionImage_Info);
        toolBar->addAction(actionResize);
        toolBar->addAction(actionFit_window);
        toolBar->addAction(actionParameter_setting);
        toolBar->addAction(actionStart);
        toolBar->addSeparator();
        toolBar->addAction(actionMeasure);
        toolBar->addSeparator();
        toolBar->addAction(actionNeighborStitching);
        toolBar->addAction(actionAbout);
        toolBar->addSeparator();

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionOpen, SIGNAL(triggered()), MainWindow, SLOT(doOpen()));
        QObject::connect(actionAbout, SIGNAL(triggered()), MainWindow, SLOT(doAbout()));
        QObject::connect(actionSave, SIGNAL(triggered()), MainWindow, SLOT(doSave()));
        QObject::connect(actionImage_Info, SIGNAL(triggered()), MainWindow, SLOT(doInfo()));
        QObject::connect(actionResize, SIGNAL(triggered()), MainWindow, SLOT(doResize()));
        QObject::connect(MainWindow, SIGNAL(imageEditable(bool)), actionSave, SLOT(setEnabled(bool)));
        QObject::connect(MainWindow, SIGNAL(imageEditable(bool)), actionImage_Info, SLOT(setEnabled(bool)));
        QObject::connect(MainWindow, SIGNAL(imageEditable(bool)), actionResize, SLOT(setEnabled(bool)));
        QObject::connect(actionFit_window, SIGNAL(triggered()), MainWindow, SLOT(doFillWindow()));
        QObject::connect(MainWindow, SIGNAL(imageEditable(bool)), actionFit_window, SLOT(setEnabled(bool)));
        QObject::connect(actionParameter_setting, SIGNAL(triggered()), MainWindow, SLOT(parameter_setting()));
        QObject::connect(actionStart, SIGNAL(triggered()), MainWindow, SLOT(start()));
        QObject::connect(mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)), MainWindow, SLOT(doChangeImage(QMdiSubWindow*)));
        QObject::connect(actionTile, SIGNAL(triggered()), mdiArea, SLOT(tileSubWindows()));
        QObject::connect(actionCascade, SIGNAL(triggered()), mdiArea, SLOT(cascadeSubWindows()));
        QObject::connect(actionMeasure, SIGNAL(triggered()), MainWindow, SLOT(domeasure()));
        QObject::connect(actionNeighborStitching, SIGNAL(triggered()), MainWindow, SLOT(neighbor_image_searching()));
        QObject::connect(actiongenerating_data, SIGNAL(triggered()), MainWindow, SLOT(generating_data()));
        QObject::connect(actionNeighbor_stitch, SIGNAL(triggered()), MainWindow, SLOT(neighbor_image_searching()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Image Stitching", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open...", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionOpen->setStatusTip(QApplication::translate("MainWindow", "Open an image from a file", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionInvert->setText(QApplication::translate("MainWindow", "Negate", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionInvert->setStatusTip(QApplication::translate("MainWindow", "Negate the image color", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionSharpen->setText(QApplication::translate("MainWindow", "Sharpen", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionSharpen->setStatusTip(QApplication::translate("MainWindow", "Sharpen the image", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionSmooth->setText(QApplication::translate("MainWindow", "Smooth", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionSmooth->setStatusTip(QApplication::translate("MainWindow", "Smooth the image", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionZoom->setText(QApplication::translate("MainWindow", "Zoom...", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionZoom->setStatusTip(QApplication::translate("MainWindow", "Change the viewing zoom", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionZoom->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Z", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionAbout->setStatusTip(QApplication::translate("MainWindow", "About this program", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionAbout->setShortcut(QApplication::translate("MainWindow", "F1", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionQuit->setStatusTip(QApplication::translate("MainWindow", "Exit the program", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionTile->setText(QApplication::translate("MainWindow", "Tile", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionTile->setStatusTip(QApplication::translate("MainWindow", "Tile the image windows", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionCascade->setText(QApplication::translate("MainWindow", "Cascade", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionCascade->setStatusTip(QApplication::translate("MainWindow", "Cascade the image windows", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionSave->setText(QApplication::translate("MainWindow", "Save As...", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionSave->setStatusTip(QApplication::translate("MainWindow", "Save the image", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionImage_Info->setText(QApplication::translate("MainWindow", "Image Info", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionImage_Info->setStatusTip(QApplication::translate("MainWindow", "Show information about the image", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionRevert->setText(QApplication::translate("MainWindow", "Revert...", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionRevert->setStatusTip(QApplication::translate("MainWindow", "Revert back to the file on disk", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionCrop->setText(QApplication::translate("MainWindow", "Crop", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionCrop->setStatusTip(QApplication::translate("MainWindow", "Crop the image based on the selection", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionColor_Adjust->setText(QApplication::translate("MainWindow", "Color Adjust...", Q_NULLPTR));
        actionResize->setText(QApplication::translate("MainWindow", "Resize...", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionResize->setStatusTip(QApplication::translate("MainWindow", "Resize the image", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionFit_window->setText(QApplication::translate("MainWindow", "Fit window", Q_NULLPTR));
        actionParameter_setting->setText(QApplication::translate("MainWindow", "setting", Q_NULLPTR));
        actionStart->setText(QApplication::translate("MainWindow", "start", Q_NULLPTR));
        actionMeasure->setText(QApplication::translate("MainWindow", "measure", Q_NULLPTR));
        actionNeighborStitching->setText(QApplication::translate("MainWindow", "NeighborStitching", Q_NULLPTR));
        actiongenerating_data->setText(QApplication::translate("MainWindow", "generating data ", Q_NULLPTR));
        actionNeighbor_stitch->setText(QApplication::translate("MainWindow", "Neighbor stitch", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File(&F)", Q_NULLPTR));
        menuImage->setTitle(QApplication::translate("MainWindow", "Image(&I)", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help(&H)", Q_NULLPTR));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window(&W)", Q_NULLPTR));
        menuMeasure_M->setTitle(QApplication::translate("MainWindow", "Measure(&M)", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "Image operations", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
