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
}

void MainWindow::on_actionPen_color_triggered()
{
    QColor customColor = QColorDialog::getColor(Qt::white, this, QString("Pick a color"), QColorDialog::ShowAlphaChannel);
    drawpanel->setColor(customColor);
}

void MainWindow::on_actionSave_triggered()
{
    QImage saveDrawing = drawpanel->getImage();
    QString filePath = QFileDialog::getSaveFileName(this, "Save Image", "", "PNG (*.png);;JPEG (*.jpg *.jpeg)");
    saveDrawing.save(filePath);
}


