#include "file.h"
#include <QVBoxLayout>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

File::File(QWidget* parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    menuBar = new QMenuBar();
    menuBar -> setStyleSheet("background-color: grey;" "border-radius: 5px;");

    openAction = new QAction("&Open");
    connect(openAction,SIGNAL(triggered()), this, SLOT(openFile()));
    menuBar -> addAction(openAction);

    saveAction = new QAction("&Save");
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));
    menuBar -> addAction(saveAction);

    mainLayout -> addWidget(menuBar);
    textEdit = new QTextEdit();
    mainLayout -> addWidget(textEdit);
    m_file = nullptr;
    m_fileName = nullptr;
}

void File::openFile()
{

    m_fileName = QFileDialog::getOpenFileName(this, "Open a file","C://Users/Arthur/QT","All files *.txt");
    m_file = new QFile(m_fileName);
    if(!m_file -> open(QFile::ReadOnly)){

        QMessageBox::warning(this, "Error", "The file is not opened for read!!");
    }
    QTextStream in(m_file);
    textEdit -> setText(in.readAll());
    m_file -> close();
}

void File::saveFile()
{
    m_file = new QFile(m_fileName);
    if (!m_file -> open(QFile::WriteOnly)){

        QMessageBox::warning(this, "Error", "The file is not opend for write");
        return;
    }

    QTextStream out (m_file);
    out << textEdit -> toPlainText();
    m_file -> close();
    textEdit -> clear();
    QMessageBox::information(this, "Message", "The file saved succesfully");

}
