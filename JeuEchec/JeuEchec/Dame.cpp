#include "Dame.h"



Dame::Dame(bool i_Black)
	: BasePieces (i_Black)
{
	if (i_Black)
	{
		m_ImageBase = loadSurface("ArtWork/Black_Queen.png");
	}
	else
	{
		m_ImageBase = loadSurface("ArtWork/White_Queen.png");
	}
}


Dame::~Dame()
{
}

void Dame::LightPossibleMoves(const Board& i_Board, const int& i_PosY, const int& i_PosX, const bool i_Vulnerable)
{
	//Check For Fou Like Movements
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


	//Check For Tour Like Movements
	//Bool that turn false when a object or a border is found to stop the check in that direction.
	bool checkRight = true;
	bool checkLeft = true;
	bool checkTop = true;
	bool checkBottom = true;

	for (int x = 1; x < 8; x++)
	{
		if (i_PosX + x < 8)
		{
			//Look for right direction
			if (checkRight && (i_Board.m_Cases[i_PosY][i_PosX + x]->m_Piece == nullptr))
			{
				if (!i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY][i_PosX + x]->SetCaseLight(true);
				}
				else
				{
					i_Board.m_Cases[i_PosY][i_PosX + x]->SetVulnerability(true);
				}
			}
			else if (checkRight && i_Board.m_Cases[i_PosY][i_PosX + x]->m_Piece->IsBlack() != IsBlack())
			{
				if (!i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY][i_PosX + x]->SetCaseLight(true);
					checkRight = false;
				}
				else
				{
					i_Board.m_Cases[i_PosY][i_PosX + x]->SetVulnerability(true);
					checkRight = false;
				}
			}
			else
			{
				checkRight = false;
			}
		}

		if (i_PosX - x > -1)
		{
			//Look for left direction
			if (checkLeft && (i_Board.m_Cases[i_PosY][i_PosX - x]->m_Piece == nullptr))
			{
				if (!i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY][i_PosX - x]->SetCaseLight(true);
				}
				else
				{
					i_Board.m_Cases[i_PosY][i_PosX - x]->SetVulnerability(true);
				}
			}
			else if (checkLeft && i_Board.m_Cases[i_PosY][i_PosX - x]->m_Piece->IsBlack() != IsBlack())
			{
				if (!i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY][i_PosX - x]->SetCaseLight(true);
					checkLeft = false;
				}
				else
				{
					i_Board.m_Cases[i_PosY][i_PosX - x]->SetVulnerability(true);
					checkLeft = false;
				}
			}
			else
			{
				checkLeft = false;
			}
		}

		if (i_PosY + x < 8)
		{
			//look for top direction
			if (checkTop && (i_Board.m_Cases[i_PosY + x][i_PosX]->m_Piece == nullptr))
			{
				if (!i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY + x][i_PosX]->SetCaseLight(true);
				}
				else
				{
					i_Board.m_Cases[i_PosY + x][i_PosX]->SetVulnerability(true);
				}
			}
			else if (checkTop && i_Board.m_Cases[i_PosY + x][i_PosX]->m_Piece->IsBlack() != IsBlack())
			{
				if (!i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY + x][i_PosX]->SetCaseLight(true);
					checkTop = false;
				}
				else
				{
					i_Board.m_Cases[i_PosY + x][i_PosX]->SetVulnerability(true);
					checkTop = false;
				}
			}
			else
			{
				checkTop = false;
			}
		}

		if (i_PosY - x > -1)
		{
			//Look for bottom direction
			if (checkBottom && (i_Board.m_Cases[i_PosY - x][i_PosX]->m_Piece == nullptr))
			{
				if (!i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY - x][i_PosX]->SetCaseLight(true);
				}
				else
				{
					i_Board.m_Cases[i_PosY - x][i_PosX]->SetVulnerability(true);
				}
			}
			else if (checkBottom && i_Board.m_Cases[i_PosY - x][i_PosX]->m_Piece->IsBlack() != IsBlack())
			{
				if (!i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY - x][i_PosX]->SetCaseLight(true);
					checkBottom = false;
				}
				else
				{
					i_Board.m_Cases[i_PosY - x][i_PosX]->SetVulnerability(true);
					checkBottom = false;
				}
			}
			else
			{
				checkBottom = false;
			}
		}
	}
}
/*
void Dame::Mouvement()
{
}


bool Dame::Illuminer()
{
	return true;
}

void Dame::Detruire()
{
}
*/