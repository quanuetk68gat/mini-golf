#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>

#include "Entity.h"

class RenderWindow
{
public:
	RenderWindow(const char* p_title, int p_w, int p_h);
	~RenderWindow(); // thêm destructor để tự động cleanup

	SDL_Texture* loadTexture(const char* p_filePath);

	void clear();
	void display();
	void cleanUp();

	void render(Entity& p_entity);
	void render(int x, int y, SDL_Texture* p_tex);
	void render(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor);
	void renderCenter(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor);

	SDL_Renderer* getRenderer() const { return renderer; } // tiện để pass renderer nếu cần

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};
