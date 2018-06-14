#include "BasePieces.h"
#include "Board.h"
#include <math.h>


BasePieces::BasePieces(bool i_Black, int i_PosX, int i_PosY)
	:m_PosX(i_PosX)
	,m_PosY(i_PosY)
	,m_Black(i_Black)
{
}


BasePieces::~BasePieces()
{
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

bool BasePieces::IsBlack()
{
	return m_Black;
}

SDL_Surface* BasePieces::loadSurface(std::string path)
{
	return IMG_Load(path.c_str());
}

void BasePieces::Render(SDL_Surface* gScreenSurface, SDL_Rect* a_CaseRect)
{
	SDL_BlitSurface(m_ImageBase, NULL, gScreenSurface, a_CaseRect);
}
