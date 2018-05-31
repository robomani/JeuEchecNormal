#include "Roi.h"



Roi::Roi(bool i_Black, int i_PosX, int i_PosY)
{
	if (i_Black)
	{
		m_ImageBase = SDL_LoadBMP("ArtWork/RoirNoir.bmp");
	}
	else
	{
		m_ImageBase = SDL_LoadBMP("ArtWork/RoiBlanc.bmp");
	}

	m_PosX = i_PosX;
	m_PosY = i_PosY;
}


Roi::~Roi()
{
}

void Roi::Roque()
{
}

void Roi::Mouvement()
{
}

bool Roi::VerifMouvLegal()
{
	return true;
}

bool Roi::Illuminer()
{
	return true;
}

void Roi::Detruire()
{
}
