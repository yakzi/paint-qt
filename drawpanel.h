#ifndef DRAWPANEL_H
#define DRAWPANEL_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>

class DrawPanel : public QWidget
{
    Q_OBJECT
public:
    explicit DrawPanel(QWidget *parent = nullptr);
    ~DrawPanel() override;

    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;

    void setColor(QColor setColor);
    void setBrushWidth (int setBrushWidth);

    QImage getImage();

private:
    QImage drawPanel;
    QPoint lastPoint;
    QColor currentColor;
    int brushWidth;
    bool isDrawing;
};

#endif // DRAWPANEL_H
