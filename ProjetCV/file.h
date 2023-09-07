#pragma once
#include <string>;
#ifndef File_H
#define File_H

#include <windows.h>
#include <shobjidl.h> 

using namespace std;
ref class File
{
PWSTR location;
public:
	File();
	void getFile(){};
	PWSTR getLocation(){};
};

#endif
