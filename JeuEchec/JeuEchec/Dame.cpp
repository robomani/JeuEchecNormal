#include "Dame.h"



Dame::Dame(bool i_Black, int i_PosX, int i_PosY)
{
	if (i_Black)
	{
		m_ImageBase = SDL_LoadBMP("ArtWork/DameNoir.bmp");
	}
	else
	{
		m_ImageBase = SDL_LoadBMP("ArtWork/DameBlanc.bmp");
	}

	m_PosX = i_PosX;
	m_PosY = i_PosY;
}


Dame::~Dame()
{
}

void Dame::Mouvement()
{
}

void Dame::VerifMouvLegal()
{
}

void Dame::Illuminer()
{
}

void Dame::Detruire()
{
}
