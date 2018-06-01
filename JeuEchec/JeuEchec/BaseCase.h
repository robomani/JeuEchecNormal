#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

class BaseCase
{
public:
	BaseCase();
	~BaseCase();

	SDL_Surface* m_ImageBase = NULL;
	SDL_Surface* m_ImageIlluminer = NULL;
	SDL_Surface* m_ImageCurrent = NULL;
	SDL_Surface* loadSurface(std::string path);

	//La bool determine si l'on veut que la case soit illuminer
	virtual bool Illuminer(bool i_Voulue);
};

