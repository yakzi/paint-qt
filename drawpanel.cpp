#include "drawpanel.h"
#include <QImage>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>

DrawPanel::DrawPanel(QWidget *parent) : QWidget(parent)
{
    start();
}

DrawPanel::~DrawPanel()
{
}

void DrawPanel::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && getIsRectangle() && !getFigureFlag())
    {
       setFigureFlag(true);
       firstPoint = event->pos();
    }
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
        if(getIsLine())
        {
            painter.drawLine(lastPoint, event->pos());
        }
        if(getIsCircle())
        {

        }
        if(getIsTriangle())
        {

        }
        if(getIsRectangle())
        {
            painter.drawRect(firstPoint.x(),firstPoint.y(), event->pos().x()-firstPoint.x(),event->pos().y()-firstPoint.y());
        }

        lastPoint = event->pos();
        update();
    }
}

void DrawPanel::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        isDrawing = false;
        setFigureFlag(false);
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

bool DrawPanel::getIsRectangle() const
{
    return isRectangle;
}

void DrawPanel::setIsRectangle(bool value)
{
    isRectangle = value;
}

bool DrawPanel::getIsCircle() const
{
    return isCircle;
}

void DrawPanel::setIsCircle(bool value)
{
    isCircle = value;
}

bool DrawPanel::getIsTriangle() const
{
    return isTriangle;
}

void DrawPanel::setIsTriangle(bool value)
{
    isTriangle = value;
}

bool DrawPanel::getIsLine() const
{
    return isLine;
}

void DrawPanel::setIsLine(bool value)
{
    isLine = value;
}

bool DrawPanel::getFigureFlag() const
{
    return figureFlag;
}

void DrawPanel::setFigureFlag(bool value)
{
    figureFlag = value;
}

void DrawPanel::setColor(QColor setColor)
{
    currentColor = setColor;
}

void DrawPanel::setBrushWidth(int setBrushWidth)
{
    brushWidth = setBrushWidth;
}

bool DrawPanel::openImage()
{
     QString openImageLocation = QFileDialog::getOpenFileName(this, tr("Open image"), "", tr("JPEG (*.jpg *.jpeg);;PNG (*.png);;BMP (*.bmp)" ));
     if(!openImageLocation.isEmpty())
     {
        drawPanel.load(openImageLocation);
        return true;
     }
     else
     {
         return false;
     }
}

void DrawPanel::start()
{
    drawPanel = QImage(this->size(), QImage::Format_RGB32);
    drawPanel.fill(Qt::white);
    setColor(Qt::black);
    setBrushWidth(1);
    setPenStyle(Qt::SolidLine);
    setCapStyle(Qt::RoundCap);
    setJoinStyle(Qt::RoundJoin);
    setIsLine(true);
    setIsCircle(false);
    setIsTriangle(false);
    setIsRectangle(false);
    setFigureFlag(false);
}

QColor DrawPanel::getColor()
{
    return currentColor;
}
