/** Arch.cpp **/

#include <iostream>
#include <string>

/*
std::string get_processor_architecture() {
	#if defined(_M_MAMD64)
	return "x64";
	#elif defined(_M_IX86)
	return "x86";
	#elif defined(_M_ARM)
	return "ARM";
	#else
	return "unknown CPU";
	#endif
}
*/

std::string get_architecture()
{
// Objective-C example
#include "TargetConditionals.h"
#if TARGET_OS_OSX
// Put CPU-independent macOS code here.
#if TARGET_CPU_ARM64
	// Put 64-bit Apple silicon macOS code here.
	return "ARM64";
#elif TARGET_CPU_X86_64
	// Put 64-bit Intel macOS code here.
	return "X86_64";
#endif
#elif TARGET_OS_MACCATALYST
	// Put Mac Catalyst-specific code here.
#elif TARGET_OS_IOS
	// Put iOS-specific code here.
#endif
}

std::string get_os_type()
{

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#ifdef _WIN64
	return "win64";
#else
	return "win32";
#endif

#elif __APPLE__
#include <TargetConditionals.h>
#if defined(TARGET_OS_OSX)
	return "macos";
#elif TARGET_OS_IPHONE
	return "iPhone IOS"
#else
	return "other APPLE os";
#endif

#elif __ANDROID__
	return "Android"

#elif __linux__
	return "GNU/Linux"

#else
	return "unknown OS"
#endif
}

int main()
{
	// std::string architecture = get_processor_architecture();
	std::string architecture = get_architecture();
	std::string ostype = get_os_type();

	std::cout << "Processor arch - " << architecture << std::endl;
	std::cout << "Running on - " << ostype << std::endl;
	return 0;
}