#ifndef SCREEN_H
#define SCREEN_H

#include <QtGui>
#include <Qt>
#include <QKeyEvent>
#include <QOpenGLFunctions>
#include <QtGui/QWindow>

#include "MathFunctions.h"
#include "vec2.h"

namespace clim{
    namespace graphics{

    class Screen : public QWindow ,
                   protected QOpenGLFunctions
    {
        Q_OBJECT

    public:
        explicit Screen();
        ~Screen();

        void setupScreen(const QString title, int width, int height);
        void resizeGL(int w, int h);
        void initializeGL();
        void paintGL();
        void keyPressEvent(QKeyEvent *event);
        void tearDownGL();
        bool event(QEvent *event);
        void timerEvent(QTimerEvent *);

          QOpenGLBuffer* createBuffer(QOpenGLBuffer::Type type,
                                      QOpenGLBuffer::UsagePattern,
                                      void* data, int byteSize);


     bool isOpen;
     math::vec2<int> getOGLFversion() const;
     math::vec2<int>& oglfversion();
     void setOglfversion(const math::vec2<int> &oglfversion);

    private:
     QOpenGLContext *m_context;
     clim::math::vec2<int> Dimension;
     bool m_show_full_screen;

        int m_frames;
        float m_time;
        math::vec2<int> m_oglfversion;

        QOpenGLShaderProgram* m_shader;
           QOpenGLTexture* m_texture;
           QOpenGLBuffer* m_vbo;
           QOpenGLBuffer* m_ibo;
           float m_textureAspect;


    };


  }
}





#endif // SCREEN_H

