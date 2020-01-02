#include "resizedialog.h"
#include "ui_resizedialog.h"


ResizeDialog::ResizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResizeDialog)
{
    ui->setupUi(this);
    ui->height->setValidator( new QIntValidator(1, 5000, this) );
    ui->width->setValidator( new QIntValidator(1, 5000, this) );
}
ResizeDialog::~ResizeDialog()
{
    delete ui;
}

void ResizeDialog::setHeight(int value)
{
    ui->height->setText(QString::number(value));
}

void ResizeDialog::setWidth(int value)
{
    ui->width->setText(QString::number(value));
}

int ResizeDialog::getHeight() const
{
    return ui->height->text().toInt();
}

int ResizeDialog::getWidth() const
{
    return ui->width->text().toInt();
}

