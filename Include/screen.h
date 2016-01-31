#ifndef SCREEN_H
#define SCREEN_H

#include <QtGui>
#include <QKeyEvent>
#include <GL/glu.h>
#include <QtGui/QOpenGLWindow>

namespace clim{
    namespace graphics{

    class Screen : public QOpenGLWindow
    {
        Q_OBJECT

    public:
        explicit Screen();
        ~Screen();

        void setupScreen(const QString title, int width, int height);
    protected:
        void resizeGL(int w, int h);

        void initializeGL();

        void paintGL();

        void keyPressEvent(QKeyEvent *event);
    private:
        bool m_show_full_screen;
    };
  }
}





#endif // SCREEN_H

