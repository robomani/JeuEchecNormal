#include "Dame.h"



Dame::Dame(bool i_Black, int i_PosX, int i_PosY)
	: BasePieces (i_PosX, i_PosY)
{
	if (i_Black)
	{
		m_ImageBase = SDL_LoadBMP("ArtWork/DameNoir.bmp");
	}
	else
	{
		m_ImageBase = SDL_LoadBMP("ArtWork/DameBlanc.bmp");
	}
}


Dame::~Dame()
{
}

void Dame::Mouvement()
{
}

bool Dame::VerifMouvLegal()
{
	return true;
}

bool Dame::Illuminer()
{
	return true;
}

void Dame::Detruire()
{
}
