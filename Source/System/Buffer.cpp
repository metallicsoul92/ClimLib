#include "..\Include\Buffer.h"

#include "..\Include\ClimOpenGL.h"
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
			OpenGL::genBuffers(1, &m_bufferID);
			OpenGL::bindBuffers(GL_ARRAY_BUFFER, m_bufferID);
			OpenGL::createBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_STATIC_DRAW);
			OpenGL::bindBuffers(GL_ARRAY_BUFFER, 0);
		}

		/////////////////////////////////////////////////
		//
		// Destructor uses the OpenGL call of delete buffer with a reference 
		// to the id as the second parameter
		//////////////////////////////////////////////////
		Buffer::~Buffer()
		{
			OpenGL::deleteBuffer(GL_ARRAY_BUFFER, &m_bufferID);
		}
		///////////////////////////////////////////////////
		//Bind function
		////////////////////////////////////////////
		void Buffer::bind() const
		{
			OpenGL::bindBuffers(GL_ARRAY_BUFFER, m_bufferID);
		}
		////////////////////////////////////////////
		// Unbind function
		///////////////////////////////////////////
		void Buffer::unbind() const
		{
			OpenGL::bindBuffers(GL_ARRAY_BUFFER, 0);
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