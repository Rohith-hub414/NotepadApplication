#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
//#include <file_path>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QFont>
#include<QtPrintSupport/qprinter.h>
#include<QtPrintSupport/qprintdialog.h>
#include <QColorDialog>
#include <QColor>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    ui->textEdit->setText(QString());
}


void MainWindow::on_actionOpen_triggered()
{
    QString filename=QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning","The file can't be opened "+file.errorString());
    }
    setWindowTitle(filename);
    QTextStream in(&file);
    QString text=in.readAll();
    ui->textEdit->setText(text);
    file.close();

}



void MainWindow::on_actionCut_triggered()
{
     ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
        ui->textEdit->paste();
}

void MainWindow::on_actionRedo_triggered()
{
        ui->textEdit->redo();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionAbout_notepad_triggered()
{
    QMessageBox::information(this,"ABOUT QT","Qt is a widget toolkit for creating graphical user interfaces as well as cross-platform applications");
}

void MainWindow::on_actionDelete_triggered()
{
    ui->textEdit->setText(QString());
}

void MainWindow::on_actionItalic_triggered()
{
        ui->textEdit->setStyleSheet("font:italic");
}

void MainWindow::on_actionbold_triggered()
{
        ui->textEdit->setStyleSheet("font:bold");
}

void MainWindow::on_actionUnderline_triggered()
{
        ui->textEdit->setStyleSheet("underline");
}


void MainWindow::on_actionSave_as_triggered()
{
    QString file_path;
    QString f=QFileDialog::getSaveFileName(this,"Save the File");
        QFile file(f);
        file_path=f;
        if(!file.open(QFile::WriteOnly|QFile::Text))
        {
            QMessageBox::warning(this,"..","File not open");
            return;
        }
        QTextStream out(&file);
        QString text=ui->textEdit->toPlainText();
        out<<text;
        file.flush();
        file.close();
}

