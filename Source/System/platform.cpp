#include "..\Include\platform.h"

namespace clim{
	namespace system{
		platform detectPlatform(){
#if defined(_WIN32) || defined(_WIN64)
			return platform::OS_WIN;
#endif
#if defined(__APPLE__) || defined(__MACH__)
			return platform::OS_MAC;
#endif
#if defined(__linux__) 
			return platform::OS_LINUX;
#endif
		}


		std::string platformToString(platform p){
			switch (p){
			case platform::OS_WIN:
				return "OS_WIN";

			case platform::OS_MAC:
				return "OS_MAC";

			case platform::OS_LINUX:
				return "OS_LINUX";

			default:
				return "Unknown OS Error";

			}
		}
	}
}