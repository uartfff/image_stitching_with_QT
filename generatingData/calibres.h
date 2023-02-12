#pragma once
#ifndef CALIBRES_H
#define CALIBRES_H

#include <QDialog>
#include <QString>
#include <QMessageBox>

namespace Ui {
	class Calibres;
}

class Calibres : public QDialog
{
	Q_OBJECT

public:
	explicit Calibres(QWidget *parent = 0);
	~Calibres();
	void show_excel(QString file_name, QStringList header, QString windows_title,int rows, int cols);

private:
	Ui::Calibres *ui;
};

#endif 