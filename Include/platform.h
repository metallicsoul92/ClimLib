#pragma once
#include <iostream>
namespace clim{
	namespace system{
		
		enum class platform  { OS_WIN , OS_MAC, OS_LINUX};
	
		platform detectPlatform();


		std::string platformToString(platform p);
		}

	}