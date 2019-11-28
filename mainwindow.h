#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <drawpanel.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    DrawPanel *drawpanel;

private slots:
    void on_actionPen_color_triggered();

};
#endif // MAINWINDOW_H
