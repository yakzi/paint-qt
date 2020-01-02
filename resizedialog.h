#ifndef RESIZEDIALOG_H
#define RESIZEDIALOG_H

#include <QDialog>
#include <QIntValidator>

namespace Ui {
class ResizeDialog;
}

class ResizeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResizeDialog(QWidget *parent = nullptr);
    ~ResizeDialog();

    int getWidth() const;
    int getHeight() const;

    void setWidth(int value);
    void setHeight(int value);

private slots:

private:
    Ui::ResizeDialog *ui;
    int width;
    int height;
};

#endif // RESIZEDIALOG_H
