#include "Pion.h"



Pion::Pion(bool i_Black, int i_PosX, int i_PosY)
	: BasePieces(i_PosX, i_PosY)
{
	if (i_Black)
	{
		m_ImageBase = SDL_LoadBMP("ArtWork/PionNoir.bmp");
	}
	else
	{
		m_ImageBase = SDL_LoadBMP("ArtWork/PionBlanc.bmp");
	}
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

