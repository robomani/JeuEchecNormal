#include "Fou.h"



Fou::Fou(bool i_Black, int i_PosX, int i_PosY)
{
	if (i_Black)
	{
		m_ImageBase = SDL_LoadBMP("ArtWork/FouNoir.bmp");
	}
	else
	{
		m_ImageBase = SDL_LoadBMP("ArtWork/FouBlanc.bmp");
	}

	m_PosX = i_PosX;
	m_PosY = i_PosY;
}


Fou::~Fou()
{
}

void Fou::Mouvement()
{
}

void Fou::VerifMouvLegal()
{
}

void Fou::Illuminer()
{
}

void Fou::Detruire()
{
}
