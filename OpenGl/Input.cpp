#include "Input.h"

Input* Input::Instance()
{
	static Input* input = new Input;
	return input;
}

void Input::Update()
{

	SDL_Event events;
	while (SDL_PollEvent(&events))
	{
		switch (events.type)
		{

			//close the window
		case SDL_QUIT:
		{
			quit = true;
			break;
		}

		case SDL_KEYDOWN:
		{
			key = events.key.keysym.sym;
			//std::cout << key << std::endl;
			break;
		}

		case SDL_KEYUP:
		{
			key = events.key.keysym.sym;
			//std::cout << key << std::endl;
			break;
		}

		case SDL_MOUSEBUTTONDOWN:
		{
			switch (events.button.button)
			{
			case SDL_BUTTON_LEFT:
			{
				std::cout << "Left Mouse Button Clicked" << std::endl;
				break;
			}

			case SDL_BUTTON_RIGHT:
			{
				std::cout << "Right Mouse Button Clicked" << std::endl;
				break;
			}

			case SDL_BUTTON_MIDDLE:
			{
				std::cout << "Middle Mouse Button Clicked" << std::endl;
				break;
			}
			break;
			}

			break;
		}

		case SDL_MOUSEBUTTONUP:
		{
			switch (events.button.button)
			{
			case SDL_BUTTON_LEFT:
			{
				std::cout << "Left Mouse Button Released" << std::endl;
				break;
			}

			case SDL_BUTTON_RIGHT:
			{
				std::cout << "Right Mouse Button Released" << std::endl;
				break;
			}

			case SDL_BUTTON_MIDDLE:
			{
				std::cout << "Middle Mouse Button Released" << std::endl;
				break;
			}
			break;
			}

			break;
		}

		case SDL_MOUSEMOTION:
		{
			auto mouseX = events.motion.xrel;
			auto mouseY = events.motion.yrel;

			//Mouse cursor position in screen space.
			auto mousePositionX = events.motion.x;
			auto mousePositionY = events.motion.y;

			//Mouse cursor position in NDC (normalized device coordinate space). Formula = Mouse position in screen space * Resolution * 2 - 1.
			auto mousePositionXNDC = mousePositionX / 1280.0f * 2.0f - 1.0f;
			auto mousePositionYNDC = mousePositionY / 720.0f * 2.0f - 1.0f;

			mousePosition.x = mousePositionXNDC;
			mousePosition.y = -mousePositionYNDC;

			if (mousePosition.x > 1.0f)
			{
				mousePosition.x = 1.0f;
			}

			if (mousePosition.x < -1.0f)
			{
				mousePosition.x = -1.0f;
			}

			if (mousePosition.y > 1.0f)
			{
				mousePosition.y = 1.0f;
			}

			if (mousePosition.x < -1.0f)
			{
				mousePosition.x = -1.0f;
			}

			break;
		}

		case SDL_MOUSEWHEEL:
		{
			auto wheelMotion = events.wheel.y;

			mouseWheel.increment += wheelMotion * 0.01f;

			if (mouseWheel.increment > 1.0f)
			{
				mouseWheel.increment = 1.0f;
			}

			if (mouseWheel.increment < 0.0f)
			{
				mouseWheel.increment = 0.0f;
			}

			break;
		}
		}
	}

}

float Input::GetMousePositionX()
{
	return mousePosition.x;
}

float Input::GetMousePositionY()
{
	return mousePosition.y;
}

float Input::GetMousePositionZ()
{
	return mousePosition.z;
}

float Input::GetMouseWheel()
{
	return mouseWheel.increment;
}

char Input::GetKey()
{
	return key;
}

bool Input::GetQuit()
{
	return quit;
}
