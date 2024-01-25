#pragma once
#include <iostream>
#include <string>

#ifdef DYNAMICLIBRARY_EXPORTS
	#define EXPORT_RULE __declspec(dllexport)
#else
	#define EXPORT_RULE __declspec(dllimport)
#endif

class Leaver {
public:
	EXPORT_RULE std::string leave(std::string& name);
};