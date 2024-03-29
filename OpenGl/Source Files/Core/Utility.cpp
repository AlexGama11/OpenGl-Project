#include "Header Files/Core/Utility.h"

HANDLE Utility::consoleHandle{nullptr};

void Utility::Initialize()
{
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Utility::Log(const std::string& outputMessage, Severity severity)
{
	//Did you forget to call Initialize()?
	assert(consoleHandle);

	SetConsoleTextAttribute(consoleHandle, static_cast<WORD>(severity));
	std::cout << outputMessage << std::endl;
	SetConsoleTextAttribute(consoleHandle, static_cast<WORD>(Severity::Default));
}

void Utility::DisplayGraphicsProfile()
{
	std::cout << glGetString(GL_VENDOR) << std::endl;
	std::cout << glGetString(GL_RENDERER) << std::endl;
	std::cout << glGetString(GL_VERSION) << std::endl;
	std::cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

void Utility::DisplayOpenGLVersion(int majorVers, int minorVers, Severity severity)
{
	//Did you forget to call Initialize()?
	assert(consoleHandle);

	SetConsoleTextAttribute(consoleHandle, static_cast<WORD>(severity));
	std::cout << "Major version is: " << majorVers << ", Minor Version is: " << minorVers << std::endl;
	SetConsoleTextAttribute(consoleHandle, static_cast<WORD>(Severity::Default));
}

void Utility::CheckGLError()
{
	//check if an error occurred and store its value
	GLenum errorValue = glGetError();

	if (errorValue == GL_NO_ERROR)
	{
		Log("Old function fixed code is working! No error has been detected!", Severity::Success);
	}

	else if (errorValue == GL_INVALID_ENUM)
	{
		Log("Old function fixed code isn't working! An invalid enum has been detected! The code was ignored!",
		    Severity::Failure);
	}

	else if (errorValue == GL_INVALID_VALUE)
	{
		Log(
			"Old function fixed code isn't working! An invalid number has been detected because it's out of range! The code was ignored!",
			Severity::Failure);
	}

	else if (errorValue == GL_INVALID_OPERATION)
	{
		Log("Old function fixed code isn't working! An invalid operation has been detected! The code was ignored!",
		    Severity::Failure);
	}

	else if (errorValue == GL_INVALID_FRAMEBUFFER_OPERATION)
	{
		Log("Old function fixed code isn't working! The framebuffer object is not complete! The code was ignored!",
		    Severity::Failure);
	}

	else if (errorValue == GL_OUT_OF_MEMORY)
	{
		Log("Old function fixed code isn't working! There is nor enough memory left to run it!", Severity::Failure);
	}

	else if (errorValue == GL_STACK_UNDERFLOW)
	{
		Log("Old function fixed code isn't working, and has caused the stack to underflow!", Severity::Failure);
	}

	else if (errorValue == GL_STACK_OVERFLOW)
	{
		Log("Old function fixed code isn't working, and has caused the stack to overflow!", Severity::Failure);
	}
}

std::string Utility::NumtoStr(int input)
{
	const std::string output = std::to_string(input);
	return output;
}

std::string Utility::NumtoStr(float input)
{
	const std::string output = std::to_string(input);
	return output;
}

std::string Utility::NumtoStr(unsigned input)
{
	const std::string output = std::to_string(input);
	return output;
}

std::string Utility::NumtoStr(double input)
{
	const std::string output = std::to_string(input);
	return output;
}

std::string Utility::NumtoStr(long double input)
{
	const std::string output = std::to_string(input);
	return output;
}

std::string Utility::NumtoStr(long input)
{
	const std::string output = std::to_string(input);
	return output;
}

std::string Utility::NumtoStr(unsigned long input)
{
	const std::string output = std::to_string(input);
	return output;
}

std::string Utility::NumtoStr(long long input)
{
	const std::string output = std::to_string(input);
	return output;
}

std::string Utility::NumtoStr(unsigned long long input)
{
	const std::string output = std::to_string(input);
	return output;
}
