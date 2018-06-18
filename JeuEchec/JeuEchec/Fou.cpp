#include "Fou.h"



Fou::Fou(bool i_Black)
	: BasePieces(i_Black)
{
	if (i_Black)
	{
		m_ImageBase = loadSurface("ArtWork/Black_Bishop.png");
	}
	else
	{
		m_ImageBase = loadSurface("ArtWork/White_Bishop.png");
	}
}


Fou::~Fou()
{
}

void Fou::LightPossibleMoves(const Board& i_Board, const int& i_PosY, const int& i_PosX, const bool i_Vulnerable)
{
	//Bool that turn off when something is found by a for loop to stop looking in that direction.
	bool plusXplusY = true;
	bool minXminY = true;
	bool plusXminY = true;
	bool minXplusY = true;

	for (int x = 1; x < 8; x++)
	{
		if (i_PosY + x < 8 && i_PosX + x < 8)
		{
			//Look for top right direction
			if (plusXplusY && (i_Board.m_Cases[i_PosY + x][i_PosX + x]->m_Piece == nullptr))
			{
				if (!i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY + x][i_PosX + x]->SetCaseLight(true);
				}
				else
				{
					i_Board.m_Cases[i_PosY + x][i_PosX + x]->SetVulnerability(true);
				}
			}
			else if (plusXplusY && i_Board.m_Cases[i_PosY + x][i_PosX + x]->m_Piece->IsBlack() != IsBlack())
			{
				if (!i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY + x][i_PosX + x]->SetCaseLight(true);
					plusXplusY = false;
				}
				else
				{
					i_Board.m_Cases[i_PosY + x][i_PosX + x]->SetVulnerability(true);
					plusXplusY = false;
				}
			}
			else
			{
				plusXplusY = false;
			}
		}

		if (i_PosY - x > -1 && i_PosX + x < 8)
		{
			//Look for bottom right direction
			if (plusXminY && (i_Board.m_Cases[i_PosY - x][i_PosX + x]->m_Piece == nullptr))
			{
				if (!i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY - x][i_PosX + x]->SetCaseLight(true);
				}
				else
				{
					i_Board.m_Cases[i_PosY - x][i_PosX + x]->SetVulnerability(true);
				}
			}
			else if (plusXminY && i_Board.m_Cases[i_PosY - x][i_PosX + x]->m_Piece->IsBlack() != IsBlack())
			{
				if (!i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY - x][i_PosX + x]->SetCaseLight(true);
					plusXminY = false;
				}
				else
				{
					i_Board.m_Cases[i_PosY - x][i_PosX + x]->SetVulnerability(true);
					plusXminY = false;
				}
			}
			else
			{
				plusXminY = false;
			}
		}

		if (i_PosY + x < 8 && i_PosX - x > -1)
		{
			//look for top left direction
			if (minXplusY && (i_Board.m_Cases[i_PosY + x][i_PosX - x]->m_Piece == nullptr))
			{
				if (!i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY + x][i_PosX - x]->SetCaseLight(true);
				}
				else
				{
					i_Board.m_Cases[i_PosY + x][i_PosX - x]->SetVulnerability(true);
				}
			}
			else if (minXplusY && i_Board.m_Cases[i_PosY + x][i_PosX - x]->m_Piece->IsBlack() != IsBlack())
			{
				if (!i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY + x][i_PosX - x]->SetCaseLight(true);
					minXplusY = false;
				}
				else
				{
					i_Board.m_Cases[i_PosY + x][i_PosX - x]->SetVulnerability(true);
					minXplusY = false;
				}
			}
			else
			{
				minXplusY = false;
			}
		}

		if (i_PosY - x > -1 && i_PosX - x > -1)
		{
			//Look for bottom left direction
			if (minXminY && (i_Board.m_Cases[i_PosY - x][i_PosX - x]->m_Piece == nullptr))
			{
				if (!i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY - x][i_PosX - x]->SetCaseLight(true);
				}
				else
				{
					i_Board.m_Cases[i_PosY - x][i_PosX - x]->SetVulnerability(true);
				}
			}
			else if (minXminY && i_Board.m_Cases[i_PosY - x][i_PosX - x]->m_Piece->IsBlack() != IsBlack())
			{
				if (!i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY - x][i_PosX - x]->SetCaseLight(true);
					minXminY = false;
				}
				else
				{
					i_Board.m_Cases[i_PosY - x][i_PosX - x]->SetVulnerability(true);
					minXminY = false;
				}
			}
			else
			{
				minXminY = false;
			}
		}
	}
}

/*
void Fou::Mouvement()
{
}

bool Fou::Illuminer()
{
	return true;
}

void Fou::Detruire()
{
}
*/