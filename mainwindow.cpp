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

int MainWindow::openDialog()
{
    QMessageBox dialog(QMessageBox::Question, tr("PaintQT"), tr("Do you want to save changes?"), QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, this);
    dialog.setButtonText(QMessageBox::Yes, tr("Yes"));
    dialog.setButtonText(QMessageBox::No, tr("No"));
    dialog.setButtonText(QMessageBox::Cancel, tr("Cancel"));
    dialog.setDefaultButton(QMessageBox::Yes);

    return dialog.exec();
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
       drawpanel->setIsLine(true);
       drawpanel->setIsCircle(false);
       drawpanel->setIsTriangle(false);
       drawpanel->setIsRectangle(false);
       ui->actionRectangle->setChecked(false);
       ui->actionTriangle->setChecked(false);
       ui->actionCircle->setChecked(false);
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
    int dialog = openDialog();
    if(dialog == QMessageBox::Yes)
    {
       on_actionSave_triggered();
       drawpanel->openImage();
    }
    else if(dialog == QMessageBox::No)
    {
        drawpanel->openImage();
    }
    else if(dialog == QMessageBox::Cancel)
    {
        return;
    }
}

void MainWindow::on_actionNew_triggered()
{
    int dialog = openDialog();
    if(dialog == QMessageBox::Yes)
    {
       on_actionSave_triggered();
       drawpanel->start();
       update();
    }
    else if(dialog == QMessageBox::No)
    {
        drawpanel->start();
        update();
    }
    else if(dialog == QMessageBox::Cancel)
    {
        return;
    }
}

void MainWindow::on_actionClose_triggered()
{
    QApplication::quit();
}
