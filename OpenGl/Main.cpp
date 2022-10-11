#include <Windows.h>
#include <gl/GL.h>

#include <iostream>
#include <SDL.h>
#include <math.h>


bool isAppRunning{ true };
Uint32 num{ 0 };
SDL_Window* window{ nullptr };
SDL_GLContext context{ nullptr };

int main(int argc, char* argv[])
{
	system("Color 09");

	struct Position
	{
		float x{ 0.0f };
		float y{ 0.0f };
		float z{ 0.0f };
	};

	Position position;

	struct Size
	{
		float increment{ 0.0f };
	};

	Size size;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == -1)
	{
		std::cout << "SDL did not initialize properly." << std::endl;
		return 0;
	}

	//set OpenGL context and profile using values assigned earlier
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

	window = SDL_CreateWindow("OpenGL Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	if (!window)
	{
		std::cout << "OpenGL Window was not created properly." << std::endl;
		return 0;
	}

	context = SDL_GL_CreateContext(window);

	if (!context)
	{
		std::cout << "OpenGL context could not be created properly. The context is either invalid or not supported by your graphics card" << std::endl;
		return 0;
	}

	while (isAppRunning)
	{

		auto num = SDL_GetTicks();

		float orbit = num * 0.01f;


		SDL_Event events;
		while (SDL_PollEvent(&events))
		{
			switch (events.type)
			{

			//close the window
			case SDL_QUIT:
			{
				isAppRunning = false;
				break;
			}

			case SDL_KEYDOWN:
			{
				//char key = events.key.keysym.sym;
				//std::cout << key << std::endl;
				break;
			}

			case SDL_KEYUP:
			{
				//char key = events.key.keysym.sym;
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

				//Mouse cursor position in NDC (normalized device coordinate space), formula = Mouse position in screen space * Resolution * 2 - 1.
				auto mousePositionXNDC = mousePositionX / 1280.0f * 2.0f - 1.0f;
				auto mousePositionYNDC = mousePositionY / 720.0f * 2.0f - 1.0f;

				if (num % 100 == 0)
				{
					position.x = std::sin(mousePositionXNDC - orbit);
					position.y = std::sin(-mousePositionYNDC + orbit);
				}

				else
				{
					position.x = std::sin(mousePositionXNDC + orbit);
					position.y = std::sin(-mousePositionYNDC - orbit);
				}
				
				if (position.x > 1.0f)
				{
					position.x = 1.0f;
				}
				
				if (position.x < -1.0f)
				{
					position.x = -1.0f;
				}
				
				if (position.y > 1.0f)
				{
					position.y = 1.0f;
				}
				
				if (position.x < -1.0f)
				{
					position.x = -1.0f;
				}

				break;
			}

			case SDL_MOUSEWHEEL:
			{
				auto wheelMotion = events.wheel.y;

				size.increment += wheelMotion * 0.01f;

				if (size.increment > 1.0f)
				{
					size.increment = 1.0f;
				}

				if (size.increment < 0.0f)
				{
					size.increment = 0.0f;
				}

				break;
			}
			}
		}

		if (num % 50 == 0)
		{
			float redValue = std::abs(std::sin(num));

			float blueValue = std::abs(std::sin(num * 0.5));

			float greenValue = std::abs(std::cos(num));

			glClear(GL_COLOR_BUFFER_BIT);


			glBegin(GL_QUADS);

			//top right corner
			glColor3f(redValue, 0.0f, 0.0f);
			glVertex3f(position.x + size.increment, position.y + size.increment, position.z + 0.0f);

			//bottom right corner
			glColor3f(0.0f, greenValue, 0.0f);
			glVertex3f(position.x + size.increment, position.y - size.increment, position.z + 0.0f);

			//bottom left corner
			glColor3f(0.0f, 0.0f, blueValue);
			glVertex3f(position.x - size.increment, position.y - size.increment, position.z + 0.0f);

			//top left corner
			glColor3f(redValue, 0.0f, blueValue);
			glVertex3f(position.x - size.increment, position.y + size.increment, position.z + 0.0f);

			glEnd();

			SDL_GL_SwapWindow(window);

		}
	}
	return 0;
}