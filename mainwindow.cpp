#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList hashAlgorithms = {
        "MD5",
        "SHA 1",
        "SHA 2",
        "SHA 224",
        "SHA 256",
        "SHA 384",
        "SHA 512"
    };
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
    QString input = ui->pteHtInput->document()->toPlainText();
    QString output;
    switch (ui->cmbHtAlgo->currentIndex()) {
        case 0:
            ui->tbHtOutput->setText(md5(input));
        break;
        case 1:
            //ui->tbHtOutput->setText(sha1(input));
        break;
        case 4:
            ui->tbHtOutput->setText(sha256(input));
        break;
    }
}
