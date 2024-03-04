#include "mainwindow.h"
#include "file.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QWidget* qwidget = nullptr;
    File file(qwidget);
    file.setWindowTitle("Text Editor 1.0");
    file.show();
    return a.exec();
}
