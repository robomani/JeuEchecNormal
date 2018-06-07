#pragma once
#include <SDL.h>

class BasePieces
{
public:
	BasePieces(int i_PosX, int i_PosY);
	~BasePieces();

	
	bool Selected;

	virtual bool VerifMouvLegal();
	virtual void Mouvement();
	//La bool determine si l'on veut que la case soit illuminer
	virtual bool Illuminer();
	virtual void Detruire();
	bool GetColor();

protected:
	bool Noir;
	int m_PosX;
	int m_PosY;
	SDL_Surface* m_ImageBase = NULL;
};

