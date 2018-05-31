#pragma once
#include <SDL.h>

class BaseCase
{
public:
	BaseCase();
	~BaseCase();

	SDL_Surface* m_ImageBase = NULL;
	SDL_Surface* m_ImageIlluminer = NULL;
	SDL_Surface* m_ImageCurrent = NULL;

	//La bool determine si l'on veut que la case soit illuminer
	virtual void Illuminer(bool i_Voulue);
};

