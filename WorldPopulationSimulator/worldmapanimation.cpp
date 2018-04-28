#include "worldMapAnimation.h"
#include <QPainter>

WorldMapAnimation::WorldMapAnimation(QWidget *parent) : QWidget(parent)
{

}

void WorldMapAnimation::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawArc(0,0,100,100,800,250);
    QWidget::paintEvent(e);
}
