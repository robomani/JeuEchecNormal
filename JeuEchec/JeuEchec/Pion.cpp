#include "Pion.h"



Pion::Pion(bool i_Black, int i_PosX, int i_PosY)
{
	if (i_Black)
	{
		m_ImageBase = SDL_LoadBMP("ArtWork/PionNoir.bmp");
	}
	else
	{
		m_ImageBase = SDL_LoadBMP("ArtWork/PionBlanc.bmp");
	}

	m_PosX = i_PosX;
	m_PosY = i_PosY;
}


Pion::~Pion()
{
}

void Pion::Promotion()
{
}
void Pion::Mouvement()
{
}

bool Pion::VerifMouvLegal()
{
	return true;
}

bool Pion::Illuminer()
{
	return true;
}

void Pion::Detruire()
{
}

