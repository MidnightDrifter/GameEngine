#include <Windows.h>
#include "..\..\SDL\include\SDL.h"
#include "..\..\SDL\include\SDL_error.h"
#include "..\..\SDL\include\SDL_main.h"
#include "..\..\SDL\include\SDL_image.h"
#include <stdio.h>
#include <string>
#include "InputManager.h"
#include "ResourceManager.h"
//#undef main

#define WINDOW_X_POS 500
#define WINDOW_Y_POS 100
#define WINDOW_NAME "FLOWEYTALE"
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 500



//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
int main(int argc, char* argv[])
{
	 ResourceManager ResourceMgr = ResourceManager();
	 InputManager InputMgr = InputManager();

	SDL_Surface* upWinSurface = ResourceMgr.loadSurface("Resources\\darkpursuit.png");
	SDL_Surface* downWinSurface = ResourceMgr.loadSurface("Resources\\dark_pursuit_small_down.png");
	SDL_Surface* leftWinSurface = ResourceMgr.loadSurface("Resources\\dark_pursuit_small_left.png");
	SDL_Surface* rightWinSurface = ResourceMgr.loadSurface("Resources\\dark_pursuit_small_right.png");
	
	bool run = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
	{
		printf("Unable to initialize SDL. \n");
		exit(-1);
	}

	//Remember, position is based from the top left corner of the screen
	SDL_Window*  pWindow = SDL_CreateWindow(WINDOW_NAME, WINDOW_X_POS, WINDOW_Y_POS, WINDOW_WIDTH, WINDOW_HEIGHT, 0); //SDL_WINDOW_OPENGL);
	SDL_Surface* pWinSurface = SDL_GetWindowSurface(pWindow);


	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == -1)
	{
		printf("Error, unable to initialize SDL_IMG\n");
		exit(222);
	}

	while (run)
	{

		SDL_FillRect(pWinSurface, NULL, 0);
		InputMgr.Update();
		SDL_Surface* pImage = upWinSurface;      //SDL_LoadBMP("darkpursuit.bmp");
	   //SDL_Surface* pImage = IMG_Load("Resources\\darkpursuit.png");

		if (InputMgr.isKeyPressed(SDL_SCANCODE_DOWN))
		{
			pImage = downWinSurface;
		}

		if (InputMgr.isKeyPressed(SDL_SCANCODE_RIGHT))
		{
			pImage = rightWinSurface;
		}

		if (InputMgr.isKeyPressed(SDL_SCANCODE_LEFT))
		{
			pImage = leftWinSurface;
		}
		
		if (InputMgr.isKeyPressed(SDL_SCANCODE_ESCAPE))
		{
			run = false;
		}





		if (pImage == NULL)
		{

			printf("Error:  unable to load image %s. \n  Error log:  %s \n", "darkpursuit.png", SDL_GetError());
			exit(111);
		}



		SDL_BlitSurface(pImage, NULL, pWinSurface, NULL);

		SDL_UpdateWindowSurface(pWindow);
		SDL_PumpEvents();

	}
	exit(1);
}