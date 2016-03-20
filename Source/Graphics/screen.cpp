#include "../../Include/screen.h"
#include "../../Include/MathFunctions.h"
#include "../../Include/MathTypes.h"
#include "../../Include/mat4.h"
#include "../../Include/Logger.h"
#include "../../Include/Debugger.h"
namespace clim{
namespace graphics{

Screen::Screen():
m_frames(0),m_time(0.0f)
{
    m_context = new QOpenGLContext();
    m_shader = new QOpenGLShaderProgram();
      m_vbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    m_ibo = new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    setSurfaceType(QSurface::OpenGLSurface);

    //Create Format
    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setVersion(4,5);
    setFormat(format);
    create();

    //create context
    m_context->setFormat(format);
    m_context->create();
    m_context->makeCurrent(this);
    QOpenGLFunctions *func = m_context->functions();

    if(!func){
        qWarning("Cannot obtain OpenGL versions");
        exit(1);
    }
    func->initializeOpenGLFunctions();

    isOpen = true;

  initializeGL();
    showNormal ();

}
void Screen::setupScreen(const QString title, int width, int height){

    this->setTitle(title);
    this->setWidth(width);
    this->setHeight(height);
    this->Dimension = math::vec2<int>(width,height);
}

Screen :: ~ Screen()
{
    m_context->doneCurrent();
    tearDownGL();
}

QOpenGLBuffer* Screen::createBuffer(QOpenGLBuffer::Type type,
                                            QOpenGLBuffer::UsagePattern usagePattern,
                                            void *data, int byteSize)
{
    QOpenGLBuffer* b = new QOpenGLBuffer(type);
    b->setUsagePattern(usagePattern);
    if (!b->create())
        qFatal("Couldn't create buffer");
    b->bind();
    b->allocate(data, byteSize);
    b->release();
    return b;
}

// The following code is the role of OpenGL scene re-set size, and the size has changed regardless of whether the window (assuming you do not use full-screen mode).
// Even when you can not resize the window (for example, you are in full-screen mode), it will run at least once - to set up our perspective at the beginning of the program.
// OpenGL scene size will be set to the size of the window where it is displayed.
void Screen::resizeGL(int w, int h)
{
    if (h == 0) // prevent dividing by zero
    {
        h = 1; // high to 1
    }
    glViewport (0, 0, w, h); // reset the current viewport
}


void Screen::initializeGL ()
{
    this->initializeOpenGLFunctions();
    m_context->makeCurrent(this);
    glClearColor(0.0f,0.0f,0.0f,1.0f);
}


void Screen::paintGL ()
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear screen and depth buffer
}

void Screen::tearDownGL(){

}


void Screen::keyPressEvent (QKeyEvent * event)
{
    switch (event-> key ())
    {
        case Qt :: Key_F2:
        {
            m_show_full_screen = !m_show_full_screen;
            if (m_show_full_screen)
            {
                showFullScreen ();
            }
            else
            {
                showNormal ();
            }
            break;
        }
        case Qt :: Key_Escape:
        {
            qApp-> exit ();
            break;
        }
    }
    }

void Screen::timerEvent(QTimerEvent *)
{
    qDebug() << "FPS:" << m_frames;
    m_frames = 0;
}
    }
}
