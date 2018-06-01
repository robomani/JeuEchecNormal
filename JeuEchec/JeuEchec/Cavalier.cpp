#include "Cavalier.h"



Cavalier::Cavalier(bool i_Black, int i_PosX, int i_PosY)
{
	if (i_Black)
	{
		m_ImageBase = loadSurface("ArtWork/CavalierNoir.bmp");
	}
	else
	{
		m_ImageBase = loadSurface("ArtWork/CavalierBlanc.bmp");
	}

	m_PosX = i_PosX;
	m_PosY = i_PosY;

	m_Rect.x = m_PosX;
	m_Rect.y = m_PosY;
	m_Rect.h = m_ImageBase->h;
	m_Rect.w = m_ImageBase->w;
}


Cavalier::~Cavalier()
{
}

void Cavalier::Mouvement()
{
}

bool Cavalier::VerifMouvLegal()
{
	return true;
}

bool Cavalier::Illuminer()
{
	return true;
}

void Cavalier::Detruire()
{
}
