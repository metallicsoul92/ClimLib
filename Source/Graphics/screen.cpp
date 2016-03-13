#include "../../Include/screen.h"
#include "../../Include/MathFunctions.h"
#include "../../Include/MathTypes.h"
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
}

// The following code is the role of OpenGL scene re-set size, and the size has changed regardless of whether the window (assuming you do not use full-screen mode).
// Even when you can not resize the window (for example, you are in full-screen mode), it will run at least once - to set up our perspective at the beginning of the program.
// OpenGL scene size will be set to the size of the window where it is displayed.
void Screen ::resizeGL(int w, int h)
{
    if (h == 0) // prevent dividing by zero
    {
        h = 1; // high to 1
    }
    glViewport (0, 0, w, h); // reset the current viewport
    // The following behavior perspective Settings screen. It means something that looks farther smaller. We do create a realistic-looking scenes.
    // 45 degree angle in accordance with the perspective here on the window width and height to calculate. 0.1f, 100.0f that we can draw the start and end depths in the scene.
    // GlMatrixMode (GL_PROJECTION) specified in the following two lines of code will affect the projection matrix (projection matrix).
    // Projection matrix is ​​responsible for adding perspective to our scene. glLoadIdentity () approximates reset. It will restore the state of the selected matrix to its original state.
    // After calling glLoadIdentity () we set a perspective view of the scene.
    // GlMatrixMode (GL_MODELVIEW) specify any new transformations will affect the modelview matrix (model view matrix).
    // Model view matrix objects stored in our message. Finally, we reset the modelview matrix. If you can not understand the meaning of these terms, please do not worry.
    // After the tutorial, I will explain. Just know that if you want to get a wonderful perspective of the scene, they must do so.
    glMatrixMode (GL_PROJECTION); // Select the projection matrix
    glLoadIdentity (); // reset the projection matrix
    // Set the viewport size
    gluPerspective (45.0f, (GLfloat) w / (GLfloat) h, 0.1f, 100.0f);

    glMatrixMode (GL_MODELVIEW); // Select the model view matrix
    glLoadIdentity (); // reset modelview matrix
    this->Dimension =clim::math::vec2<int>(w,h);
}


void Screen::initializeGL ()
{

    glShadeModel (GL_SMOOTH); // Enables shadows smooth


    glClearColor (0.0f, 0.0f, 0.0f, 0.0f); // Black Background
    glClearDepth (1.0f); // set the depth buffer
    glEnable (GL_DEPTH_TEST); // enable depth testing
    glDepthFunc (GL_LEQUAL); // made by the type of depth test

    // Then tell OpenGL we want to be the best perspective correction. This will be a very slight impact on performance. But look a little better so that perspective.
    glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Tell system perspective correction
}


void Screen::paintGL ()
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear screen and depth buffer
    glLoadIdentity (); // reset the current model view matrix
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
