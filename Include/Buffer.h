#pragma once


namespace clim {
	namespace system{

		class Buffer
		{
		private:
			unsigned int m_bufferID;
			unsigned int m_componentCount;

		public:
			Buffer(float* data, unsigned int count, unsigned int componentCount);
			~Buffer();
			void bind() const;
			void unbind() const;
			unsigned int getComponentCount() const;
        };
	}
}
