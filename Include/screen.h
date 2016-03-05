#ifndef SCREEN_H
#define SCREEN_H

#include <QtGui>
#include <Qt>
#include <QKeyEvent>
#include <GL/glu.h>
#include <QtGui/QOpenGLWindow>

#include "MathFunctions.h"
#include "vec2.h"

namespace clim{
    namespace graphics{

    class Screen : public QOpenGLWindow
    {
        Q_OBJECT

    public:
        explicit Screen();
        ~Screen();

        void setupScreen(const QString title, int width, int height);
 bool isOpen;



    protected:
        void resizeGL(int w, int h);

        void initializeGL();

        void paintGL();

        void keyPressEvent(QKeyEvent *event);
    private:
        clim::math::vec2<int> Dimension;

        bool m_show_full_screen;


    public:

    };


  }
}





#endif // SCREEN_H

