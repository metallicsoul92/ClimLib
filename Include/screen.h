#ifndef SCREEN_H
#define SCREEN_H

#include <QMainWindow>
#include <QTGui>
#include <QtGui/QOpenGLFunctions>

class QPainter;
class QOpenGLContext;
class QOpenGLPaintDevice;

namespace clim{
    namespace graphics{

    class Screen : public QMainWindow, protected QOpenGLFunctions{
        Q_OBJECT
    public:
        explicit Screen(QMainWindow *parent = 0);
        ~Screen();

        virtual void render(QPainter *painter);
        virtual void render();

        virtual void initialize();

        void setAnimating(bool animating);

        void initializet(QString title,int width, int height);
    public slots:
        void renderLater();
        void renderNow();

    protected:
        bool event(QEvent *event) Q_DECL_OVERRIDE;

        void exposeEvent(QExposeEvent *event) Q_DECL_OVERRIDE;

    private:
        bool m_update_pending;
        bool m_animating;

        QOpenGLContext *m_context;
        QOpenGLPaintDevice *m_device;
    };
  }
}





#endif // SCREEN_H

