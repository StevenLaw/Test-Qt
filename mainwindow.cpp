#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string>
#include <QLoggingCategory>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList hashAlgorithms = {"SHA 256", "MD5"};
    ui->cmbHtAlgo->insertItems(0, hashAlgorithms);
    ui->cmbHfAlgo->insertItems(0, hashAlgorithms);
}

//QStringList MainWindow::

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

void MainWindow::on_btnHfBrowse_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"));
    ui->txtHfFile->setText(filename);
}

void MainWindow::on_btnHtHash_clicked()
{
    switch (ui->cmbHtAlgo->currentIndex()) {
        case 0:
            QString input = ui->pteHtInput->document()->toPlainText();
            ui->tbHtOutput->setText(sha256(input));
            break;
    }
}
