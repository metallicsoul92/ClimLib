#include "../../Include/screen.h"
#include "../../Include/MathFunctions.h"
#include "../../Include/MathTypes.h"
#include "../../Include/mat4.h"

namespace clim{
namespace graphics{

Screen::Screen():
QOpenGLWindow()
{
    showNormal ();
    isOpen = true;
}
void Screen::setupScreen(const QString title, int width, int height){

    this->setTitle(title);
    this->setWidth(width);
    this->setHeight(height);
    this->Dimension = math::vec2<int>(width,height);
}

Screen :: ~ Screen()
{
    makeCurrent();
    tearDownGL();
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
    initializeOpenGLFunctions();

    glClearColor(0.0f,0.0f,0.0f,1.0f);
}


void Screen::paintGL ()
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear screen and depth buffer
}

void Screen::tearDownGL(){

}

QString Screen::ContextInformation()
    {
      QString glType;
      QString glVersion;
      QString glProfile;

      // Get Version Information
      //glType = (context()->isOpenGLES()) ? "OpenGL ES" : "OpenGL";
      if(context()->isOpenGLES()){
          glType= "OpenGL ES";
      }else{
          glType= "OpenGL";
      }
      glVersion = reinterpret_cast<const char*>(glGetString(GL_VERSION));

      // Get Profile Information
    #define CASE(c) case QSurfaceFormat::c: glProfile = #c; break
      switch (format().profile())
      {
        CASE(NoProfile);
        CASE(CoreProfile);
        CASE(CompatibilityProfile);
      }
    #undef CASE

      QString temp = "Type: ";
      temp.append(glType);
      temp.append("\nVersion: ");
      temp.append(glVersion);
      temp.append("\nProfile: ");
      temp.append(glProfile);

      return temp;
      // qPrintable() will print our QString w/o quotes around it.
      //qDebug() << qPrintable(glType) << qPrintable(glVersion) << "(" << qPrintable(glProfile) << ")";

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
            update();
            break;
        }
        case Qt :: Key_Escape:
        {
            qApp-> exit ();
            break;
        }
    }
    }
    }
}
