#include "Tour.h"



Tour::Tour(bool i_Black, int i_PosX, int i_PosY)
	: BasePieces(i_PosX, i_PosY)
{
	if (i_Black)
	{
		m_ImageBase = SDL_LoadBMP("ArtWork/TourNoir.bmp");
	}
	else
	{
		m_ImageBase = SDL_LoadBMP("ArtWork/TourBlanc.bmp");
	}
}


Tour::~Tour()
{
}

void Tour::Mouvement()
{
}

bool Tour::VerifMouvLegal()
{
	return true;
}

bool Tour::Illuminer()
{
	return true;
}

void Tour::Detruire()
{
}
