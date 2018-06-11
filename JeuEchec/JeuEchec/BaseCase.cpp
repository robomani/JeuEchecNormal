#include "BaseCase.h"
#include "BasePieces.h"


BaseCase::BaseCase(int i_PosX, int i_PosY, BasePieces* i_Piece)
	: PosX (i_PosX)
	, PosY (i_PosY)
	, m_Piece (i_Piece)
	, m_CaseRect(SDL_Rect())
{
	m_CaseRect.x = PosX * 50;
	m_CaseRect.y = PosY * 50;
	m_CaseRect.w = 50;
	m_CaseRect.h = 50;
}


BaseCase::~BaseCase()
{
}

bool BaseCase::Illuminer(bool i_Voulue)
{
	if (i_Voulue)
	{
		m_ImageCurrent = m_ImageIlluminer;
	}
	else
	{
		m_ImageCurrent = m_ImageBase;
	}
	return true;
}

SDL_Surface* BaseCase::loadSurface(std::string path)
{
	return IMG_Load(path.c_str());
}

void BaseCase::Render(SDL_Surface* gScreenSurface)
{
	if (m_Piece != nullptr)
	{
		m_Piece->Render(gScreenSurface, &m_CaseRect);
	}
}