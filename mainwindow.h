#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>
#include <QMainWindow>
#include <QFileDialog>

#include <Hashing/Sha256/sha256.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_Exit_triggered();

    void on_btnEdfBrowse_clicked();

    void on_btnHfBrowse_clicked();

    void on_btnHtHash_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
