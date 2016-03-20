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
    m_context->functions()->initializeOpenGLFunctions();

    if(!m_context->functions()){
        qWarning("Cannot obtain OpenGL versions");
        exit(1);
    }


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
    m_context->functions()->glClearColor(0.0f,0.0f,0.0f,1.0f);
}


void Screen::paintGL ()
{
   m_context->functions()->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear screen and depth buffer
}

void Screen::tearDownGL(){

}

bool Screen::event(QEvent *event)
{
    switch(event->type()){
    case QEvent::None:
        break;
    case QEvent::Timer:
        break;
    case QEvent::MouseButtonPress:
        break;
    case QEvent::MouseButtonRelease:
        break;
    case QEvent::MouseButtonDblClick:
        break;
    case QEvent::MouseMove:
        break;
    case QEvent::KeyPress:
        break;
    case QEvent::KeyRelease:
        break;
    case QEvent::FocusIn:
        break;
    case QEvent::FocusOut:
        break;
    case QEvent::FocusAboutToChange:
        break;
    case QEvent::Enter:
        break;
    case QEvent::Leave:
        break;
    case QEvent::Paint:
        break;
    case QEvent::Move:
        break;
    case QEvent::Resize:
        break;
    case QEvent::Create:
        break;
    case QEvent::Destroy:
        break;
    case QEvent::Show:
        break;
    case QEvent::Hide:
        break;
    case QEvent::Quit:
        break;
    case QEvent::ParentChange:
        break;
    case QEvent::ParentAboutToChange:
        break;
    case QEvent::ThreadChange:
        break;
    case QEvent::WindowActivate:
        break;
    case QEvent::WindowDeactivate:
        break;
    case QEvent::ShowToParent:
        break;
    case QEvent::HideToParent:
        break;
    case QEvent::Wheel:
        break;
    case QEvent::WindowTitleChange:
        break;
    case QEvent::WindowIconChange:
        break;
    case QEvent::ApplicationWindowIconChange:
        break;
    case QEvent::ApplicationFontChange:
        break;
    case QEvent::ApplicationLayoutDirectionChange:
        break;
    case QEvent::ApplicationPaletteChange:
        break;
    case QEvent::PaletteChange:
        break;
    case QEvent::Clipboard:
        break;
    case QEvent::Speech:
        break;
    case QEvent::MetaCall:
        break;
    case QEvent::SockAct:
        break;
    case QEvent::WinEventAct:
        break;
    case QEvent::DeferredDelete:
        break;
    case QEvent::DragEnter:
        break;
    case QEvent::DragMove:
        break;
    case QEvent::DragLeave:
        break;
    case QEvent::Drop:
        break;
    case QEvent::DragResponse:
        break;
    case QEvent::ChildAdded:
        break;
    case QEvent::ChildPolished:
        break;
    case QEvent::ChildRemoved:
        break;
    case QEvent::ShowWindowRequest:
        break;
    case QEvent::PolishRequest:
        break;
    case QEvent::Polish:
        break;
    case QEvent::LayoutRequest:
        break;
    case QEvent::UpdateRequest:
        break;
    case QEvent::UpdateLater:
        break;
    case QEvent::EmbeddingControl:
        break;
    case QEvent::ActivateControl:
        break;
    case QEvent::DeactivateControl:
        break;
    case QEvent::ContextMenu:
        break;
    case QEvent::InputMethod:
        break;
    case QEvent::TabletMove:
        break;
    case QEvent::LocaleChange:
        break;
    case QEvent::LanguageChange:
        break;
    case QEvent::LayoutDirectionChange:
        break;
    case QEvent::Style:
        break;
    case QEvent::TabletPress:
        break;
    case QEvent::TabletRelease:
        break;
    case QEvent::OkRequest:
        break;
    case QEvent::HelpRequest:
        break;
    case QEvent::IconDrag:
        break;
    case QEvent::FontChange:
        break;
    case QEvent::EnabledChange:
        break;
    case QEvent::ActivationChange:
        break;
    case QEvent::StyleChange:
        break;
    case QEvent::IconTextChange:
        break;
    case QEvent::ModifiedChange:
        break;
    case QEvent::MouseTrackingChange:
        break;
    case QEvent::WindowBlocked:
        break;
    case QEvent::WindowUnblocked:
        break;
    case QEvent::WindowStateChange:
        break;
    case QEvent::ReadOnlyChange:
        break;
    case QEvent::ToolTip:
        break;
    case QEvent::WhatsThis:
        break;
    case QEvent::StatusTip:
        break;
    case QEvent::ActionChanged:
        break;
    case QEvent::ActionAdded:
        break;
    case QEvent::ActionRemoved:
        break;
    case QEvent::FileOpen:
        break;
    case QEvent::Shortcut:
        break;
    case QEvent::ShortcutOverride:
        break;
    case QEvent::WhatsThisClicked:
        break;
    case QEvent::ToolBarChange:
        break;
    case QEvent::QueryWhatsThis:
        break;
    case QEvent::EnterWhatsThisMode:
        break;
    case QEvent::LeaveWhatsThisMode:
        break;
    case QEvent::ZOrderChange:
        break;
    case QEvent::HoverEnter:
        break;
    case QEvent::HoverLeave:
        break;
    case QEvent::HoverMove:
        break;
    case QEvent::AcceptDropsChange:
        break;
    case QEvent::ZeroTimerEvent:
        break;
    case QEvent::GraphicsSceneMouseMove:
        break;
    case QEvent::GraphicsSceneMousePress:
        break;
    case QEvent::GraphicsSceneMouseRelease:
        break;
    case QEvent::GraphicsSceneMouseDoubleClick:
        break;
    case QEvent::GraphicsSceneContextMenu:
        break;
    case QEvent::GraphicsSceneHoverEnter:
        break;
    case QEvent::GraphicsSceneHoverMove:
        break;
    case QEvent::GraphicsSceneHoverLeave:
        break;
    case QEvent::GraphicsSceneHelp:
        break;
    case QEvent::GraphicsSceneDragEnter:
        break;
    case QEvent::GraphicsSceneDragMove:
        break;
    case QEvent::GraphicsSceneDragLeave:
        break;
    case QEvent::GraphicsSceneDrop:
        break;
    case QEvent::GraphicsSceneWheel:
        break;
    case QEvent::KeyboardLayoutChange:
        break;
    case QEvent::DynamicPropertyChange:
        break;
    case QEvent::TabletEnterProximity:
        break;
    case QEvent::TabletLeaveProximity:
        break;
    case QEvent::NonClientAreaMouseMove:
        break;
    case QEvent::NonClientAreaMouseButtonPress:
        break;
    case QEvent::NonClientAreaMouseButtonRelease:
        break;
    case QEvent::NonClientAreaMouseButtonDblClick:
        break;
    case QEvent::MacSizeChange:
        break;
    case QEvent::ContentsRectChange:
        break;
    case QEvent::MacGLWindowChange:
        break;
    case QEvent::FutureCallOut:
        break;
    case QEvent::GraphicsSceneResize:
        break;
    case QEvent::GraphicsSceneMove:
        break;
    case QEvent::CursorChange:
        break;
    case QEvent::ToolTipChange:
        break;
    case QEvent::NetworkReplyUpdated:
        break;
    case QEvent::GrabMouse:
        break;
    case QEvent::UngrabMouse:
        break;
    case QEvent::GrabKeyboard:
        break;
    case QEvent::UngrabKeyboard:
        break;
    case QEvent::MacGLClearDrawable:
        break;
    case QEvent::StateMachineSignal:
        break;
    case QEvent::StateMachineWrapped:
        break;
    case QEvent::TouchBegin:
        break;
    case QEvent::TouchUpdate:
        break;
    case QEvent::TouchEnd:
        break;
    case QEvent::NativeGesture:
        break;
    case QEvent::RequestSoftwareInputPanel:
        break;
    case QEvent::CloseSoftwareInputPanel:
        break;
    case QEvent::WinIdChange:
        break;
    case QEvent::Gesture:
        break;
    case QEvent::GestureOverride:
        break;
    case QEvent::ScrollPrepare:
        break;
    case QEvent::Scroll:
        break;
    case QEvent::Expose:
        break;
    case QEvent::InputMethodQuery:
        break;
    case QEvent::OrientationChange:
        break;
    case QEvent::TouchCancel:
        break;
    case QEvent::ThemeChange:
        break;
    case QEvent::SockClose:
        break;
    case QEvent::PlatformPanel:
        break;
    case QEvent::StyleAnimationUpdate:
        break;
    case QEvent::ApplicationStateChange:
        break;
    case QEvent::WindowChangeInternal:
        break;
    case QEvent::ScreenChangeInternal:
        break;
    case QEvent::User:
        break;
    case QEvent::MaxUser:
        break;
    case QEvent::Close :
        isOpen = false;
        this->close();
        return true;
    }
    return false;
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
