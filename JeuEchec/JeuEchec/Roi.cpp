#include "Roi.h"



Roi::Roi(bool i_Black, int i_PosX, int i_PosY)
{
	if (i_Black)
	{
		m_ImageBase = loadSurface("ArtWork/RoirNoir.bmp");
	}
	else
	{
		m_ImageBase = loadSurface("ArtWork/RoiBlanc.bmp");
	}

	m_PosX = i_PosX;
	m_PosY = i_PosY;

	m_Rect.x = m_PosX;
	m_Rect.y = m_PosY;
	m_Rect.h = m_ImageBase->h;
	m_Rect.w = m_ImageBase->w;
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
