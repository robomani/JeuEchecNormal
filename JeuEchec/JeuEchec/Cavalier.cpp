#include "Cavalier.h"



Cavalier::Cavalier(bool i_Black, int i_PosX, int i_PosY)
{
	if (i_Black)
	{
		m_ImageBase = SDL_LoadBMP("ArtWork/CavalierNoir.bmp");
	}
	else
	{
		m_ImageBase = SDL_LoadBMP("ArtWork/CavalierBlanc.bmp");
	}

	m_PosX = i_PosX;
	m_PosY = i_PosY;
}


Cavalier::~Cavalier()
{
}

void Cavalier::Mouvement()
{
}

void Cavalier::VerifMouvLegal()
{
}

void Cavalier::Illuminer()
{
}

void Cavalier::Detruire()
{
}
