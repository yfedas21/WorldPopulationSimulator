//Derived QSFMLCanvas class specifically for the animation instance of world map
//Largely adapted from 1.6 SFML tutorial -> https://www.sfml-dev.org/tutorials/1.6/graphics-qt.php
//Many upgrade solutions were found here  -> https://github.com/SFML/SFML/wiki/Tutorial:-Integrating-SFML-into-Qt

/*#ifndef SFMLANIMATION_H
#define SFMLANIMATION_H

#include "qsfmlcanvas.h"
#include "SFML/Graphics.hpp"

class SFMLAnimation : public QSFMLCanvas
{
public :

    MyCanvas(QWidget* Parent, const QPoint& Position, const QSize& Size) :
    QSFMLCanvas(Parent, Position, Size)
    {

    }

private :

    void OnInit()
    {
        // Load the image
        myImage.LoadFromFile("datas/qt/sfml.png");

        // Setup the sprite
        mySprite.SetImage(myImage);
        mySprite.SetCenter(mySprite.GetSize() / 2.f);
    }

    void OnUpdate()
    {
        // Clear screen
        Clear(sf::Color(0, 128, 0));

        // Rotate the sprite
        mySprite.Rotate(GetFrameTime() * 100.f);

        // Draw it
        Draw(mySprite);
    }

    sf::Image  myImage;
    sf::Sprite mySprite;
};


#endif // QSFMLANIMATION_H*/
