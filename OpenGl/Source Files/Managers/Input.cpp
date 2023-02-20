#include "Header Files/Managers/Input.h"

Input* Input::Instance()
{
	static auto input = new Input;
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
				switch (events.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					{
						quit = true;
						break;
					}

				default:
					{
						Utility::Log("Key was Pressed!");
						break;
					}
				}

				break;
			}


		case SDL_KEYUP:
			{
				switch (events.key.keysym.sym)
				{
				default:

					key = events.key.keysym.sym;
				/*std::string keyString = "A Key was Released: " + key;
				Utility::Log(keyString);*/

					break;
				}

				break;
			}

		case SDL_MOUSEBUTTONDOWN:
			{
				switch (events.button.button)
				{
				case SDL_BUTTON_LEFT:
					{
						//Utility::Log("Left Mouse Button Clicked");
						break;
					}

				case SDL_BUTTON_RIGHT:
					{
						//Utility::Log("Right Mouse Button Clicked");
						break;
					}

				case SDL_BUTTON_MIDDLE:
					{
						//Utility::Log("Middle Mouse Button Clicked");
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
						//Utility::Log("Left Mouse Button Released");
						break;
					}

				case SDL_BUTTON_RIGHT:
					{
						//Utility::Log("Right Mouse Button Released");
						break;
					}

				case SDL_BUTTON_MIDDLE:
					{
						//Utility::Log("Middle Mouse Button Released");
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

				//std::cout << "Mouse Position on the X axis is: " << mousePosition.x << "; Mouse Position on the Y axis is: " << mousePosition.y << std::endl;

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
