#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_Exit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_btnEdfBrowse_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"));
    ui->txtEdfFile->setText(filename);
}
