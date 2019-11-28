#include "drawpanel.h"
#include <QImage>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>

#include<QDebug>

DrawPanel::DrawPanel(QWidget *parent) : QWidget(parent)
{
    drawPanel = QImage(this->size(), QImage::Format_RGB32);
    drawPanel.fill(Qt::white);
    setColor(Qt::red);
    setBrushWidth(2);
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
        QPen currentPen;
        currentPen.setStyle(Qt::SolidLine);
        currentPen.setColor(currentColor);
        currentPen.setCapStyle(Qt::RoundCap);
        currentPen.setJoinStyle(Qt::RoundJoin);
        painter.setPen(currentPen);
        painter.drawLine(lastPoint, event->pos());
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


void DrawPanel::setColor(QColor setColor)
{
    currentColor = setColor;
}

void DrawPanel::setBrushWidth(int setBrushWidth)
{
    brushWidth = setBrushWidth;
}
