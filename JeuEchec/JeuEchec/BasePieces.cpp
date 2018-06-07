#include "BasePieces.h"
#include <math.h>


BasePieces::BasePieces(int i_PosX, int i_PosY)
	:m_PosX(i_PosX)
	,m_PosY(i_PosY)
{
}


BasePieces::~BasePieces()
{
}

bool BasePieces::VerifMouvLegal()
{
	
	//if (floor(mousePosX/50) >= 0 && Floor(mousePosX/50) <= 7 && Floor(mousePosY/50) >= 0 && Floor(mousePosY/50) <= 7)
	{
		return true;
	}
}

void BasePieces::Mouvement()
{
	//if (VerifMouvLegal())
	{
		//m_PosX = Floor(mousePosX / LenghtOfTiles);
		//m_PosY = loor(mousePosY / LenghtOfTiles);
	}
}

bool BasePieces::Illuminer()
{
	return true;
}

void BasePieces::Detruire()
{
	m_PosX = -1;
	m_PosY = -1;
}

bool BasePieces::GetColor()
{
	return Noir;
}

SDL_Surface* BasePieces::loadSurface(std::string path)
{
	return IMG_Load(path.c_str());
}

void BasePieces::Render(SDL_Surface* gScreenSurface, SDL_Rect* a_CaseRect)
{
	SDL_BlitSurface(m_ImageBase, NULL, gScreenSurface, a_CaseRect);
}
