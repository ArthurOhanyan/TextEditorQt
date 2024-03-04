#ifndef FILE_H
#define FILE_H
#include <QMenu>
#include <QMenuBar>
#include <QTextEdit>
#include <QFile>
#include <QString>
#include "qwidget.h"

class File : public QWidget
{
    Q_OBJECT

public:
    File(QWidget*);

private slots:
    void openFile();
   // void editFile();
   void saveFile();
private:

    QMenuBar* menuBar;
    QMenu* fileMenu;
    QTextEdit* textEdit;
    QAction* openAction;
    QAction* editAction;
    QAction* saveAction;
    QFile* m_file;
    QString m_fileName;
};

#endif // FILE_H
