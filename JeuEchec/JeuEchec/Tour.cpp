#include "Tour.h"



Tour::Tour(bool i_Black, int i_PosX, int i_PosY)
{
	if (i_Black)
	{
		m_ImageBase = loadSurface("ArtWork/TourNoir.bmp");
	}
	else
	{
		m_ImageBase = loadSurface("ArtWork/TourBlanc.bmp");
	}

	m_PosX = i_PosX;
	m_PosY = i_PosY;

	m_Rect.x = m_PosX;
	m_Rect.y = m_PosY;
	m_Rect.h = m_ImageBase->h;
	m_Rect.w = m_ImageBase->w;
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
