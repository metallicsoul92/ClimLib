#ifndef SCREEN_H
#define SCREEN_H

#include <QtGui>
#include <Qt>
#include <QKeyEvent>
#include <QOpenGLFunctions>
#include <QtGui/QOpenGLWindow>

#include "MathFunctions.h"
#include "vec2.h"

namespace clim{
    namespace graphics{

    class Screen : public QOpenGLWindow ,
                   protected QOpenGLFunctions
    {
        Q_OBJECT

    public:
        explicit Screen();
        ~Screen();

        void setupScreen(const QString title, int width, int height);
        void resizeGL(int w, int h)Q_DECL_OVERRIDE;
        void initializeGL()Q_DECL_OVERRIDE;
        void paintGL() Q_DECL_OVERRIDE;
        void keyPressEvent(QKeyEvent *event);
        void tearDownGL();
        QString ContextInformation();
     bool isOpen;
    private:

        clim::math::vec2<int> Dimension;
        bool m_show_full_screen;



    };


  }
}





#endif // SCREEN_H

