#ifndef MATHTYPES_H
#define MATHTYPES_H

namespace clim{
	namespace math{
		template<typename t>
		struct vec2{
			t x;
			t y;
	
			vec2(t x, t y)
			{
				this->x = x;
				this->y = y;
			}

			vec2()
			{
				this->x = 0;
				this->y = 0;
				
			}
		};
		template<typename t>
		struct vec3{
			t x;
			t y;
			t z;
			
			vec3(t x, t y, t z)
			{
				this->x = x;
				this->y = y;
				this->z = z;
			}

			vec3()
			{
				this->x = 0;
				this->y = 0;
				this->z = 0;
			}
		};
		template<typename t>
		struct vec4{
			t x;
			t y;
			t z;
			t w;

			vec4(t x, t y, t z, t w)
			{
				this->x = x;
				this->y = y;
				this->z = z;
				this->w = w;
			}
			
			vec4()
			{
				this->x = 0;
				this->y = 0;
				this->z = 0;
				this->w = 0;
			}
		};
						
		template<typename t>
		struct mat4{
			t element[16];
		};
		
		typedef vec2<int> vec2i;
		typedef vec2<unsigned int> vec2ui;
		typedef vec2<float> vec2f;
		typedef vec2<double> vec2d;
	
		typedef vec3<int> vec3i;
		typedef vec3<unsigned int> vec3ui;
		typedef vec3<float> vec3f;
		typedef vec3<double> vec3d;

		typedef vec4<int> vec4i;
		typedef vec4<unsigned int> vec4ui;
		typedef vec4<float> vec4f;
		typedef vec4<double> vec4d;

		typedef mat4<int> mat4i;
		typedef mat4<unsigned int> mat4ui;
		typedef mat4<float> mat4f;
		typedef mat4<double> mat4d;
	}
	
	
	
}




#endif