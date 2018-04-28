//The implementation file for SFML Graphics embedded into Qt as a custom Widget
//Largely adapted from 1.6 SFML tutorial -> https://www.sfml-dev.org/tutorials/1.6/graphics-qt.php
//Many upgrade solutions were found here  -> https://github.com/SFML/SFML/wiki/Tutorial:-Integrating-SFML-into-Qt

/*#include "qsfmlcanvas.h"
#include "SFML/Graphics.hpp"

//(Fix ME https://github.com/SFML/SFML/wiki/Tutorial:-Integrating-SFML-into-Qt))
//QSFMLCanvas::QSFMLCanvas(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime) :
//QWidget       (Parent),
//myInitialized (false)
//{
    // Setup some states to allow direct rendering into the widget
    //setAttribute(Qt::WA_PaintOnScreen);
    //setAttribute(Qt::WA_OpaquePaintEvent);
    //setAttribute(Qt::WA_NoSystemBackground);

    // Set strong focus to enable keyboard events to be received
   // setFocusPolicy(Qt::StrongFocus);

    // Setup the widget geometry
    //move(Position);
    //resize(Size);

    // Setup the timer
    //myTimer.setInterval(FrameTime); (FIX ME) https://github.com/SFML/SFML/wiki/Tutorial:-Integrating-SFML-into-Qt
//}


#ifdef Q_WS_X11
    #include <Qt/qx11info_x11.h>
    #include <X11/Xlib.h>
#endif

void QSFMLCanvas::showEvent(QShowEvent*)
{
    if (!myInitialized)
    {
        // Under X11, we need to flush the commands sent to the server to ensure that
        // SFML will get an updated view of the windows
        #ifdef Q_WS_X11
            XFlush(QX11Info::display());
        #endif

        // Create the SFML window with the widget handle
        //sf::Window::create(winId()); (FIX ME https://github.com/SFML/SFML/wiki/Tutorial:-Integrating-SFML-into-Qt)

        // Let the derived class do its specific stuff
        OnInit();

        // Setup the timer to trigger a refresh at specified framerate
        //connect(&myTimer, SIGNAL(timeout()), this, SLOT(repaint())); (FIX ME: https://github.com/SFML/SFML/wiki/Tutorial:-Integrating-SFML-into-Qt)
        //myTimer.start();

        myInitialized = true;
    }
}

QPaintEngine* QSFMLCanvas::paintEngine() const
{
    return 0;
}

void QSFMLCanvas::paintEvent(QPaintEvent*)
{
    // Let the derived class do its specific stuff
    OnUpdate();

    // Display on screen
    sf::Window::display();
}*/
