#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void razbor_stroki();
    int exception(int k);
    void working(int g);


private slots:
    void on_ok_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
