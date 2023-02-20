#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <assert.h>
#include "gl.h"

class Utility
{
public:
	enum class Severity
	{
		Default = 5,
		Success = 10,
		Warning = 14,
		Failure = 12
	};

	static void Initialize();

	static void Log(const std::string& outputMessage, Severity severity = Severity::Default);

	static void DisplayGraphicsProfile();

	static void DisplayOpenGLVersion(int majorVers, int minorVers, Severity severity = Severity::Default);

	static void CheckGLError();

	static std::string NumtoStr(int input);

	static std::string NumtoStr(float input);

	static std::string NumtoStr(unsigned input);

	static std::string NumtoStr(double input);

	static std::string NumtoStr(long double input);

	static std::string NumtoStr(long input);

	static std::string NumtoStr(unsigned long input);

	static std::string NumtoStr(long long input);

	static std::string NumtoStr(unsigned long long input);

private:
	static HANDLE consoleHandle;
};
