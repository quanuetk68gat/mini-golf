#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>

#include "RenderWindow.h"
#include "Entity.h"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
	:window(nullptr), renderer(nullptr)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
	if (!window)
	{
		std::cout << "\u274C Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		std::cout << "\u274C Renderer failed to init. Error: " << SDL_GetError() << std::endl;
	}
}

RenderWindow::~RenderWindow()
{
	cleanUp();
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = IMG_LoadTexture(renderer, p_filePath);
	if (!texture)
	{
		std::cout << " Failed to load texture: " << SDL_GetError() << std::endl;
	}
	return texture;
}

void RenderWindow::cleanUp()
{
	if (renderer)
		SDL_DestroyRenderer(renderer);
	if (window)
		SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& p_entity)
{
	SDL_Rect src = p_entity.getCurrentFrame();
	SDL_Rect dst;
	dst.x = p_entity.getPos().x + (src.w - src.w * p_entity.getScale().x) / 2;
	dst.y = p_entity.getPos().y + (src.h - src.h * p_entity.getScale().y) / 2;
	dst.w = src.w * p_entity.getScale().x;
	dst.h = src.h * p_entity.getScale().y;

	SDL_RenderCopyEx(renderer, p_entity.getTex(), &src, &dst, p_entity.getAngle(), nullptr, SDL_FLIP_NONE);
}

void RenderWindow::render(int x, int y, SDL_Texture* p_tex)
{
	if (!p_tex)
	{
		std::cout << "Texture is null in render(int, int). Error: " << SDL_GetError() << std::endl;
		return;
	}

	SDL_Rect src{ 0, 0, 0, 0 };
	SDL_QueryTexture(p_tex, nullptr, nullptr, &src.w, &src.h);

	SDL_Rect dst{ x, y, src.w, src.h };
	SDL_RenderCopy(renderer, p_tex, &src, &dst);
}

void RenderWindow::render(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor)
{
	if (!font)
	{
		std::cout << " Font is null in render(). Error: " << TTF_GetError() << std::endl;
		return;
	}

	SDL_Surface* surfaceMessage = TTF_RenderText_Blended(font, p_text, textColor);
	if (!surfaceMessage)
	{
		std::cout << " TTF_RenderText_Blended failed in render(): " << TTF_GetError() << std::endl;
		return;
	}

	SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	if (!message)
	{
		std::cout << " SDL_CreateTextureFromSurface failed: " << SDL_GetError() << std::endl;
		SDL_FreeSurface(surfaceMessage);
		return;
	}

	SDL_Rect src = { 0, 0, surfaceMessage->w, surfaceMessage->h };
	SDL_Rect dst = { static_cast<int>(p_x), static_cast<int>(p_y), src.w, src.h };

	SDL_RenderCopy(renderer, message, &src, &dst);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(message);
}

void RenderWindow::renderCenter(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor)
{
	if (!font)
	{
		std::cout << " Font is null in renderCenter(). Error: " << TTF_GetError() << std::endl;
		return;
	}

	SDL_Surface* surfaceMessage = TTF_RenderText_Blended(font, p_text, textColor);
	if (!surfaceMessage)
	{
		std::cout << " TTF_RenderText_Blended failed in renderCenter(): " << TTF_GetError() << std::endl;
		return;
	}

	SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	if (!message)
	{
		std::cout << " SDL_CreateTextureFromSurface failed: " << SDL_GetError() << std::endl;
		SDL_FreeSurface(surfaceMessage);
		return;
	}

	SDL_Rect src = { 0, 0, surfaceMessage->w, surfaceMessage->h };
	SDL_Rect dst = { static_cast<int>(640 / 2 - src.w / 2 + p_x), static_cast<int>(480 / 2 - src.h / 2 + p_y), src.w, src.h };

	SDL_RenderCopy(renderer, message, &src, &dst);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(message);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}
