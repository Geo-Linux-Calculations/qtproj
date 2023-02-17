#ifndef QTPROJ_H
#define QTPROJ_H

#include <QMainWindow>
#include "ui_qtproj.h"

#define PROJSTRDEF "+proj=longlat +datum=WGS84 +no_defs"

class QtProj : public QMainWindow
{
    Q_OBJECT

public:
    QtProj(QWidget *parent = 0);
    ~QtProj();

private:
    Ui::QtProjClass ui;

private slots:
    void slot_transfer();
};

#endif // QTPROJ_H
