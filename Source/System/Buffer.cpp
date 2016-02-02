#include "../../Include/Buffer.h"
#include <QOpenGLContext>
#include <QOpenGLFunctions>
namespace clim{
	namespace system{

		///////////////////////////////////////////////////
		//
		//Buffer Constructor contains the data, size of the data, and component count
		// Algorithm :  generate buffer via OpenGL call
		//              bind the buffer via OpenGL call
		//              Create Buffer data via OpenGL call
		//              bind buffer back to 0

		Buffer::Buffer(float* data, unsigned count, unsigned componentCount)
		: m_componentCount(componentCount)
		{
            QOpenGLFunctions *f = (QOpenGLFunctions *)malloc(sizeof(QOpenGLFunctions *));
           f->glGenBuffers(1, &m_bufferID);
            f->glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
            f->glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_STATIC_DRAW);
            f->glBindBuffer(GL_ARRAY_BUFFER, 0);
            free(f);
		}

		/////////////////////////////////////////////////
		//
		// Destructor uses the OpenGL call of delete buffer with a reference 
		// to the id as the second parameter
		//////////////////////////////////////////////////
		Buffer::~Buffer()
        {
            QOpenGLFunctions *f = (QOpenGLFunctions *)malloc(sizeof(QOpenGLFunctions *));

            f->glDeleteBuffers(GL_ARRAY_BUFFER, &m_bufferID);

		}
		///////////////////////////////////////////////////
		//Bind function
		////////////////////////////////////////////
		void Buffer::bind() const
		{
QOpenGLFunctions *f = (QOpenGLFunctions *)malloc(sizeof(QOpenGLFunctions *));
            f->glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
		}
		////////////////////////////////////////////
		// Unbind function
		///////////////////////////////////////////
		void Buffer::unbind() const
		{
            QOpenGLFunctions *f = (QOpenGLFunctions *)malloc(sizeof(QOpenGLFunctions *));
            f->glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		///////////////////////////////
		// component count getter method;
		////////////////////////////////
		unsigned Buffer::getComponentCount() const
		{
			return m_componentCount;
		}
	}
}
