#include "BaseCase.h"
#include "BasePieces.h"
#include "Board.h"


BaseCase::BaseCase(int i_PosX, int i_PosY, std::shared_ptr<BasePieces> i_Piece)
	: PosX (i_PosX)
	, PosY (i_PosY)
	, m_Piece (i_Piece)
	, m_CaseRect(SDL_Rect())
{
	m_ImageLight = loadSurface("ArtWork/Alight_Case.png");
	m_CaseRect.x = PosX * 50;
	m_CaseRect.y = PosY * 50;
	m_CaseRect.w = 50;
	m_CaseRect.h = 50;
	isAlight = false;
}


BaseCase::~BaseCase()
{
	SDL_FreeSurface(m_ImageLight);
	m_ImageLight = nullptr;
}

void BaseCase::SetCaseLight(bool i_toLight, Board& i_board)
{
	isAlight = i_toLight;
	if (i_toLight == true)
	{
		i_board.canMove = true;
	}
}

void BaseCase::SetVulnerability(bool i_Vulnerability)
{
	isVulnerable = i_Vulnerability;
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

	if (isAlight)
	{
		SDL_BlitSurface(m_ImageLight, NULL, gScreenSurface, &m_CaseRect);
	}
}