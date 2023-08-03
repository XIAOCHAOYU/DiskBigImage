#include "mainwindow.h"
//opencv
#include <opencv2/core/core.hpp>
//stxxl
#include <stxxl.h>
//stxxld的容器
#include"OutOfCore/DiskBigImageInterface.h"
#include "OutOfCore/DiskBigImage.hpp"
//boost的容器
#include <boost/timer.hpp>
#include <boost/format.hpp>
#include "OutOfCore/DiskBigImage.hpp"
#include "OutOfCore/DiskBigImage.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    InitUI();
	
	QString file_name = "D:/SOURCE/image/位图/Large.jpg";
    QByteArray cdata = file_name.toLocal8Bit();
    std::string spath(cdata);

	big_image = load_disk_image<Vec3b>(spath);

}

MainWindow::~MainWindow()
{
   
}

void MainWindow::InitUI()
{
    setMinimumSize(800, 800);
}

void MainWindow::stxxlDiskSetPath()
{
    //配置虚拟文件大小和路径,程序运行结束后删除，finish
    stxxl::config* cfg = stxxl::config::get_instance();
    std::string base_file = "/var/tmp/stxxl/stxxl.tmp";
    stxxl::disk_config disk1(base_file, 100 * 1024 * 1024, "syscall autogrow delete_on_exit");
    cfg->add_disk(disk1);
}