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

			if (num % 50 == 0)
			{
				float redValue = std::abs(std::sin(num));

				std::cout << redValue << std::endl;
				
				float blueValue = std::abs(std::sin(num * 0.5));

				std::cout << blueValue << std::endl;
				
				float greenValue = std::abs(std::cos(num));

				std::cout << greenValue << std::endl;


				glClear(GL_COLOR_BUFFER_BIT);

				glBegin(GL_TRIANGLES);

					glColor3f(redValue, 0.0f, 0.0f);
					glVertex3f(0.5f, 0.5f, 0.0f);

					glColor3f(0.0f, greenValue, 0.0f);
					glVertex3f(0.75f, -0.5f, 0.0f);

					glColor3f(0.0f, 0.0f, blueValue);
					glVertex3f(0.25f, -0.5f, 0.0f);

				glEnd();


				glBegin(GL_QUADS);

					glColor3f(redValue, 0.0f, 0.0f);
					glVertex3f(-0.25f, 0.5f, 0.0f);

					glColor3f(0.0f, greenValue, 0.0f);
					glVertex3f(-0.25f, -0.5f, 0.0f);

					glColor3f(0.0f, 0.0f, blueValue);
					glVertex3f(-0.75f, -0.5f, 0.0f);

					glColor3f(redValue, 0.0f, blueValue);
					glVertex3f(-0.75f, 0.5f, 0.0f);

				glEnd();

				SDL_GL_SwapWindow(window);

			}
		}
	

	system("pause");
	return 0;
}