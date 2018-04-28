#include "worldMapAnimation.h"
#include <QPainter>

WorldMapAnimation::WorldMapAnimation(QWidget *parent) : QWidget(parent)
{

}

void WorldMapAnimation::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,1600,900,QPixmap("://Resources/WorldMap.png"));
    QWidget::paintEvent(e);
}
