#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

class BasePieces
{
public:
	BasePieces();
	~BasePieces();

	virtual bool VerifMouvLegal();
	virtual void Mouvement();
	//La bool determine si l'on veut que la case soit illuminer
	virtual bool Illuminer();
	virtual void Detruire();
	SDL_Surface* loadSurface(std::string path);

protected:
	int m_PosX;
	int m_PosY;
	SDL_Surface* m_ImageBase = NULL;
	SDL_Rect m_Rect;
};

