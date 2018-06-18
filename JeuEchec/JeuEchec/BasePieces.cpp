#include "BasePieces.h"
#include "Board.h"
#include <math.h>


BasePieces::BasePieces(bool i_Black)
	: m_Black(i_Black)
{
}


BasePieces::~BasePieces()
{
}

void BasePieces::LightPossibleMoves(const Board& i_Board,const int& i_PosY,const int& i_PosX, const bool i_Vulnerable)
{

}

void BasePieces::Mouvement()
{

}

void BasePieces::Destroy()
{
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
