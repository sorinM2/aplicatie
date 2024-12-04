#include <SDL.h>

int main(int argc, char** argv)
{
	SDL_Renderer* renderer;
	SDL_Window* window;
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Fereastra", 100, 100, 720, 360, NULL);
	SDL_Delay(3000);
	
	return 0;
}