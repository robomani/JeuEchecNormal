#include "BasePieces.h"
#include "Board.h"
#include "Roi.h"
#include <iostream>
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

bool BasePieces::IsKingVulnerableAtPos(const Board& i_Board, const int& i_PreviousPosY, const int& i_PreviousPosX, const int& i_PosY, const int& i_PosX)
{
	bool isKingVulnerable = false;
	BasePieces* previousPiece = nullptr;

	if (i_Board.m_Cases[i_PosY][i_PosX]->m_Piece != nullptr)
	{
		previousPiece = i_Board.m_Cases[i_PosY][i_PosX]->m_Piece;
	}

	i_Board.m_Cases[i_PosY][i_PosX]->m_Piece = i_Board.m_Cases[i_PreviousPosY][i_PreviousPosX]->m_Piece;
	i_Board.m_Cases[i_PreviousPosY][i_PreviousPosX]->m_Piece = nullptr;



	for (int i = 0; i < i_Board.m_Cases.size(); i++)
	{
		for (int x = 0; x < i_Board.m_Cases[i].size(); x++)
		{
			if (i_Board.m_Cases[i][x]->m_Piece != nullptr && i_Board.m_Cases[i][x]->m_Piece->IsBlack() != IsBlack())
			{
				i_Board.m_Cases[i][x]->isVulnerable = false;	
				i_Board.m_Cases[i][x]->m_Piece->LightPossibleMoves(i_Board, i, x, true);
			}
		}
	}

	for (int i = 0; i < i_Board.m_Cases.size(); i++)
	{
		for (int x = 0; x < i_Board.m_Cases[i].size(); x++)
		{
			if (i_Board.m_Cases[i][x]->m_Piece != nullptr && i_Board.m_Cases[i][x]->m_Piece->isKing)
			{
				if (i_Board.m_Cases[i][x]->m_Piece->IsBlack() == IsBlack())
				{
					std::cout << i_Board.m_Cases[i][x]->m_Piece->IsBlack() << " : Roi  " << std::endl;
					std::cout << IsBlack() << " : Moi" << std::endl;

					isKingVulnerable = i_Board.m_Cases[i][x]->isVulnerable;
					std::cout << i_Board.m_Cases[i][x]->isVulnerable << std::endl;
				}
			}
		}
	}

	i_Board.m_Cases[i_PreviousPosY][i_PreviousPosX]->m_Piece = i_Board.m_Cases[i_PosY][i_PosX]->m_Piece;
	i_Board.m_Cases[i_PosY][i_PosX]->m_Piece = previousPiece;
	for (int i = 0; i < i_Board.m_Cases.size(); i++)
	{
		for (int x = 0; x < i_Board.m_Cases[i].size(); x++)
		{
			if (i_Board.m_Cases[i][x]->m_Piece != nullptr && i_Board.m_Cases[i][x]->m_Piece->IsBlack() != IsBlack())
			{
				i_Board.m_Cases[i][x]->isVulnerable = false;
				i_Board.m_Cases[i][x]->m_Piece->LightPossibleMoves(i_Board, i, x, true);
			}
		}
	}

	return isKingVulnerable;
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
