#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

class BasePieces
{
public:
	BasePieces(bool i_Black, int i_PosX, int i_PosY);
	~BasePieces();

	
	bool Selected;

	virtual bool VerifMouvLegal();
	virtual void Mouvement();
	//La bool determine si l'on veut que la case soit illuminer
	virtual bool Illuminer();
	virtual void Detruire();
	void Render(SDL_Surface* gScreenSurface, SDL_Rect* a_CaseRect);
	bool GetColor();
	SDL_Surface* loadSurface(std::string path);

protected:
	bool m_Black;
	int m_PosX;
	int m_PosY;
	SDL_Surface* m_ImageBase = NULL;
	SDL_Rect m_Rect;
};

