//The header file for SFML Graphics embedded into Qt
//Largely adapted from 1.6 SFML tutorial -> https://www.sfml-dev.org/tutorials/1.6/graphics-qt.php
//Many upgrade solutions were found here  -> https://github.com/SFML/SFML/wiki/Tutorial:-Integrating-SFML-into-Qt

#ifndef QSMLCANVAS_H
#define QSMLCANVAS_H

#include <qwidget.h>
#include "SFML/Graphics.hpp"

class QSFMLCanvas : public QWidget, public sf::RenderWindow
{
public :

    QSFMLCanvas(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime = 0);

    virtual ~QSFMLCanvas();

private :

    virtual void OnInit();

    virtual void OnUpdate();

    virtual QPaintEngine* paintEngine() const;

    virtual void showEvent(QShowEvent*);

    virtual void paintEvent(QPaintEvent*);

    //QTimer myTimer; (FIX ME https://github.com/SFML/SFML/wiki/Tutorial:-Integrating-SFML-into-Qt)
    bool   myInitialized;
};


#endif // QSMLCANVAS_H
