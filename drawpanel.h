#ifndef DRAWPANEL_H
#define DRAWPANEL_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QFileDialog>

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
    bool openImage();
    void start();

    QColor getColor();
    QImage getImage();

    QColor getPrevColor() const;
    void setPrevColor(const QColor &value);

    Qt::PenStyle getPenStyle() const;
    void setPenStyle(const Qt::PenStyle &value);

    Qt::PenCapStyle getCapStyle() const;
    void setCapStyle(const Qt::PenCapStyle &value);

    Qt::PenJoinStyle getJoinStyle() const;
    void setJoinStyle(const Qt::PenJoinStyle &value);

    bool getIsRectangle() const;
    void setIsRectangle(bool value);

    bool getIsCircle() const;
    void setIsCircle(bool value);

    bool getIsTriangle() const;
    void setIsTriangle(bool value);

    bool getIsLine() const;
    void setIsLine(bool value);

    bool getFigureFlag() const;
    void setFigureFlag(bool value);

private:
    QImage drawPanel;
    QPoint lastPoint;
    QPoint firstPoint;
    QColor currentColor;
    QColor prevColor;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle capStyle;
    Qt::PenJoinStyle joinStyle;

    int brushWidth;
    bool isDrawing;
    bool isRectangle;
    bool isCircle;
    bool isTriangle;
    bool isLine;


    bool figureFlag;
};

#endif // DRAWPANEL_H
