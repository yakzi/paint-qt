#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      drawpanel(new DrawPanel(this))
{
    ui->setupUi(this);
    setCentralWidget(drawpanel);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete drawpanel;
}

void MainWindow::on_actionPen_color_triggered()
{
    QColor customColor = QColorDialog::getColor(Qt::white, this, QString("Pick a color"), QColorDialog::ShowAlphaChannel);
    drawpanel->setColor(customColor);
}

void MainWindow::on_actionSave_triggered()
{
    QImage saveDrawing = drawpanel->getImage();
    QString filePath = QFileDialog::getSaveFileName(this, "Save Image", "", "PNG (*.png);;JPEG (*.jpg *.jpeg);;BMP (*.bmp)");
    saveDrawing.save(filePath);
}

void MainWindow::on_actionPen_size_triggered()
{
    bool correct = false;

    int size = QInputDialog::getInt(this, "Set pen size", "Pen size", 1, 1, 50, 1, &correct);

    if (correct)
    {
        drawpanel->setBrushWidth(size);
    }
}

void MainWindow::on_actionEraser_triggered()
{
    if(ui->actionEraser->isChecked() == true)
    {
       drawpanel->setPrevColor(drawpanel->getColor());
       drawpanel->setColor(Qt::white);
    }
    if(ui->actionEraser->isChecked() == false)
    {
        drawpanel->setColor(drawpanel->getPrevColor());
    }
}

void MainWindow::on_actionRectangle_triggered()
{
    if(ui->actionRectangle->isChecked() == true)
    {
        ui->actionCircle->setChecked(false);
        ui->actionTriangle->setChecked(false);
        drawpanel->setIsRectangle(true);
        drawpanel->setIsCircle(false);
        drawpanel->setIsTriangle(false);
        drawpanel->setIsLine(false);
    }
    if(ui->actionRectangle->isChecked() == false)
    {
        drawpanel->setIsRectangle(false);
        drawpanel->setIsCircle(false);
        drawpanel->setIsTriangle(false);
        drawpanel->setIsLine(true);
    }
}

void MainWindow::on_actionCircle_triggered()
{
    if(ui->actionCircle->isChecked() == true)
    {
        ui->actionRectangle->setChecked(false);
        ui->actionTriangle->setChecked(false);
        drawpanel->setIsCircle(true);
        drawpanel->setIsRectangle(false);
        drawpanel->setIsTriangle(false);
        drawpanel->setIsLine(false);
    }
    if(ui->actionCircle->isChecked() == false)
    {
        drawpanel->setIsRectangle(false);
        drawpanel->setIsCircle(false);
        drawpanel->setIsTriangle(false);
        drawpanel->setIsLine(true);
    }
}

void MainWindow::on_actionTriangle_triggered()
{
    if(ui->actionTriangle->isChecked() == true)
    {
        ui->actionRectangle->setChecked(false);
        ui->actionCircle->setChecked(false);
        drawpanel->setIsTriangle(true);
        drawpanel->setIsCircle(false);
        drawpanel->setIsRectangle(false);
        drawpanel->setIsLine(false);
    }
    if(ui->actionTriangle->isChecked() == false)
    {
        drawpanel->setIsRectangle(false);
        drawpanel->setIsCircle(false);
        drawpanel->setIsTriangle(false);
        drawpanel->setIsLine(true);
    }
}

void MainWindow::on_actionOpen_triggered()
{
    drawpanel->openImage();
}

void MainWindow::on_actionNew_triggered()
{
    drawpanel->start();
    update();
}
