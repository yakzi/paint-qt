#include "drawpanel.h"
#include <QImage>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>

DrawPanel::DrawPanel(QWidget *parent) : QWidget(parent)
{
    drawPanel = QImage(this->size(), QImage::Format_RGB32);
    drawPanel.fill(Qt::white);
    setColor(Qt::black);
    setBrushWidth(1);
    setPenStyle(Qt::SolidLine);
    setCapStyle(Qt::RoundCap);
    setJoinStyle(Qt::RoundJoin);
}

DrawPanel::~DrawPanel()
{
}

void DrawPanel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();
        isDrawing = true;
    }
}

void DrawPanel::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && isDrawing == true)
    {
        QPainter painter(&drawPanel);
        //TODO: ADD POSSIBILITY TO CHANGE LINE STYLE, AND CAP STYLE
        painter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
        painter.drawLine(lastPoint, event->pos());
        //painter.drawRect(event->pos().x(),event->pos().y(),10,10);
        lastPoint = event->pos();
        update();
    }
}

void DrawPanel::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        isDrawing = false;
    }
}


void DrawPanel::paintEvent(QPaintEvent *event)
{
    //QPainter painter(this);
    //painter.drawImage(event->rect(), drawPanel, drawPanel.rect());
        QRect dirtyRect = event->rect();
        QPainter painter(this);
        painter.drawImage(dirtyRect,drawPanel,dirtyRect);
}


void DrawPanel::resizeEvent(QResizeEvent *event)
{
    drawPanel = QImage(this->size(), QImage::Format_RGB32);
    drawPanel.fill(Qt::white);
}

QImage DrawPanel::getImage()
{
    return drawPanel;
}

QColor DrawPanel::getPrevColor() const
{
    return prevColor;
}

void DrawPanel::setPrevColor(const QColor &value)
{
    prevColor = value;
}

Qt::PenStyle DrawPanel::getPenStyle() const
{
    return penStyle;
}

void DrawPanel::setPenStyle(const Qt::PenStyle &value)
{
    penStyle = value;
}

Qt::PenCapStyle DrawPanel::getCapStyle() const
{
    return capStyle;
}

void DrawPanel::setCapStyle(const Qt::PenCapStyle &value)
{
    capStyle = value;
}

Qt::PenJoinStyle DrawPanel::getJoinStyle() const
{
    return joinStyle;
}

void DrawPanel::setJoinStyle(const Qt::PenJoinStyle &value)
{
    joinStyle = value;
}

void DrawPanel::setColor(QColor setColor)
{
    currentColor = setColor;
}

void DrawPanel::setBrushWidth(int setBrushWidth)
{
    brushWidth = setBrushWidth;
}

QColor DrawPanel::getColor()
{
    return currentColor;
}
