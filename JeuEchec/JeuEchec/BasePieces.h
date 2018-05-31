#pragma once
#include <SDL.h>

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

protected:
	int m_PosX;
	int m_PosY;
	SDL_Surface* m_ImageBase = NULL;
};

