#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class aplicatie
{
public:

	void Init()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow("Fereastra", 100, 100, 720, 360, NULL);
		renderer = SDL_CreateRenderer(window, -1, 0);
		PlayerTexture = IMG_LoadTexture(renderer, "assets/download.jpg");
		PlayerRect.w = 100;
		PlayerRect.h = 100;
		PlayerRect.x = 0;
		PlayerRect.y = 0;
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	}

	void Update()
	{

	}

	void PollEvents()
	{
		SDL_Event e;
		int plusx = 0, plusy = 0;
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT:
				SDL_Quit();
				isRunning = false;
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
					case SDLK_d:
						plusx+=2;
						break;
					case SDLK_a:
						plusx-=2;
						break;
					case SDLK_s:
						plusy += 2;
						break;
					case SDLK_w:
						plusy -= 2;
						break;
				}
			}
		}
		PlayerRect.x += plusx;
		PlayerRect.y += plusy;
	}

	void Render()
	{
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, PlayerTexture, NULL, &PlayerRect);
		SDL_RenderPresent(renderer);
	}

	bool Running() { return isRunning; }
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* PlayerTexture;
	SDL_Rect PlayerRect;

	bool isRunning = true;
};
int main(int argc, char** argv)
{
	int MS = 1000;
	int FPS = 60;
	float frame_duration = (float)MS / (float)FPS;

	aplicatie* app = new aplicatie;
	app->Init();

	int cnt = 0;
	while (app->Running())
	{
		float start_time = SDL_GetTicks();
		app->PollEvents();
		app->Update();
		app->Render();
		float end_time = SDL_GetTicks();
		float duration = end_time - start_time;
		float time_left = frame_duration - duration;
		if ( time_left > 0 )
			SDL_Delay(time_left);
		std::cout << cnt++ << std::endl;
	}
	return 0;
}