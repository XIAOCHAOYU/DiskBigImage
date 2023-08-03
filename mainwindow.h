#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qslider.h>
#include <qspinbox.h>
#include <qcheckbox.h>
/* library module */
#include <boost/timer.hpp>
#include <boost/shared_ptr.hpp>
/* outofcore module */
#include "OutOfCore/BasicType.h"
#include "OutOfCore/DiskBigImageInterface.h"
#include "OutOfCore/DiskBigImage.hpp"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow* ui;
private:
    void InitUI();
    void stxxlDiskSetPath();
private:
    boost::shared_ptr<DiskBigImageInterface<Vec3b>>big_image;
private:
    
};
#endif // MAINWINDOW_H
