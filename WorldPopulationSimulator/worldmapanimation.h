#ifndef WORLDMAPANIMATION_H
#define WORLDMAPANIMATION_H

#include <QWidget>

class WorldMapAnimation : public QWidget
{
    Q_OBJECT
public:
    explicit WorldMapAnimation(QWidget *parent = nullptr);

   protected:
   void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // WORLDMAPANIMATION_H
