#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <drawpanel.h>
#include <QMainWindow>
#include <QFileDialog>
#include <QInputDialog>

#include <QDebug>

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
    void on_actionSave_triggered();
    void on_actionPen_size_triggered();
    void on_actionEraser_triggered();

    void on_actionRectangle_triggered();
    void on_actionCircle_triggered();
    void on_actionTriangle_triggered();
    void on_actionOpen_triggered();
};
#endif // MAINWINDOW_H
