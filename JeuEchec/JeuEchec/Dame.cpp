#include "Dame.h"



Dame::Dame(bool i_Black, int i_PosX, int i_PosY)
{
	if (i_Black)
	{
		m_ImageBase = loadSurface("ArtWork/DameNoir.bmp");
	}
	else
	{
		m_ImageBase = loadSurface("ArtWork/DameBlanc.bmp");
	}

	m_PosX = i_PosX;
	m_PosY = i_PosY;

	m_Rect.x = m_PosX;
	m_Rect.y = m_PosY;
	m_Rect.h = m_ImageBase->h;
	m_Rect.w = m_ImageBase->w;
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
