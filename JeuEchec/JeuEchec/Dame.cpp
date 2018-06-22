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

void Dame::LightPossibleMoves(Board& i_Board, const int& i_PosY, const int& i_PosX, const bool i_Vulnerable)
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
					if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY + x, i_PosX + x))
					{
						i_Board.m_Cases[i_PosY + x][i_PosX + x]->SetCaseLight(true, i_Board);
					}
				}
				else
				{
					i_Board.m_Cases[i_PosY + x][i_PosX + x]->SetVulnerability(true);
				}
			}
			else if (plusXplusY && i_Board.m_Cases[i_PosY + x][i_PosX + x]->m_Piece->IsBlack() == IsBlack())
			{
				plusXplusY = false;

				if (i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY + x][i_PosX + x]->SetVulnerability(true);
				}

			}
			else if (plusXplusY && i_Board.m_Cases[i_PosY + x][i_PosX + x]->m_Piece->IsBlack() != IsBlack())
			{
				if (!i_Vulnerable)
				{
					if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY + x, i_PosX + x))
					{
						i_Board.m_Cases[i_PosY + x][i_PosX + x]->SetCaseLight(true, i_Board);
					}
					plusXplusY = false;
				}
				else
				{
					i_Board.m_Cases[i_PosY + x][i_PosX + x]->SetVulnerability(true);
					plusXplusY = false;
				}
			}
		}

		if (i_PosY - x > -1 && i_PosX + x < 8)
		{
			//Look for bottom right direction
			if (plusXminY && (i_Board.m_Cases[i_PosY - x][i_PosX + x]->m_Piece == nullptr))
			{
				if (!i_Vulnerable)
				{
					if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY - x, i_PosX + x))
					{
						i_Board.m_Cases[i_PosY - x][i_PosX + x]->SetCaseLight(true, i_Board);
					}
				}
				else
				{
					i_Board.m_Cases[i_PosY - x][i_PosX + x]->SetVulnerability(true);
				}
			}
			else if (plusXminY && i_Board.m_Cases[i_PosY - x][i_PosX + x]->m_Piece->IsBlack() == IsBlack())
			{
				plusXminY = false;

				if (i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY - x][i_PosX + x]->SetVulnerability(true);
				}
			}
			else if (plusXminY && i_Board.m_Cases[i_PosY - x][i_PosX + x]->m_Piece->IsBlack() != IsBlack())
			{
				if (!i_Vulnerable)
				{
					if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY - x, i_PosX + x))
					{
						i_Board.m_Cases[i_PosY - x][i_PosX + x]->SetCaseLight(true, i_Board);
					}
					plusXminY = false;
				}
				else
				{
					i_Board.m_Cases[i_PosY - x][i_PosX + x]->SetVulnerability(true);
					plusXminY = false;
				}
			}
		}

		if (i_PosY + x < 8 && i_PosX - x > -1)
		{
			//look for top left direction
			if (minXplusY && (i_Board.m_Cases[i_PosY + x][i_PosX - x]->m_Piece == nullptr))
			{
				if (!i_Vulnerable)
				{
					if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY + x, i_PosX - x))
					{
						i_Board.m_Cases[i_PosY + x][i_PosX - x]->SetCaseLight(true, i_Board);
					}
				}
				else
				{
					i_Board.m_Cases[i_PosY + x][i_PosX - x]->SetVulnerability(true);
				}
			}
			else if (minXplusY && i_Board.m_Cases[i_PosY + x][i_PosX - x]->m_Piece->IsBlack() == IsBlack())
			{
				minXplusY = false;

				if (!i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY + x][i_PosX - x]->SetVulnerability(true);
				}
			}
			else if (minXplusY && i_Board.m_Cases[i_PosY + x][i_PosX - x]->m_Piece->IsBlack() != IsBlack())
			{
				if (!i_Vulnerable)
				{
					if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY + x, i_PosX - x))
					{
						i_Board.m_Cases[i_PosY + x][i_PosX - x]->SetCaseLight(true, i_Board);
					}
					minXplusY = false;
				}
				else
				{
					i_Board.m_Cases[i_PosY + x][i_PosX - x]->SetVulnerability(true);
					minXplusY = false;
				}
			}
		}

		if (i_PosY - x > -1 && i_PosX - x > -1)
		{
			//Look for bottom left direction
			if (minXminY && (i_Board.m_Cases[i_PosY - x][i_PosX - x]->m_Piece == nullptr))
			{
				if (!i_Vulnerable)
				{
					if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY - x, i_PosX - x))
					{
						i_Board.m_Cases[i_PosY - x][i_PosX - x]->SetCaseLight(true, i_Board);
					}
				}
				else
				{
					i_Board.m_Cases[i_PosY - x][i_PosX - x]->SetVulnerability(true);
				}
			}
			else if (minXminY && i_Board.m_Cases[i_PosY - x][i_PosX - x]->m_Piece->IsBlack() == IsBlack())
			{
				minXminY = false;

				if (i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY - x][i_PosX - x]->SetVulnerability(true);
				}
			}
			else if (minXminY && i_Board.m_Cases[i_PosY - x][i_PosX - x]->m_Piece->IsBlack() != IsBlack())
			{
				if (!i_Vulnerable)
				{
					if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY - x, i_PosX - x))
					{
						i_Board.m_Cases[i_PosY - x][i_PosX - x]->SetCaseLight(true, i_Board);
					}
					minXminY = false;
				}
				else
				{
					i_Board.m_Cases[i_PosY - x][i_PosX - x]->SetVulnerability(true);
					minXminY = false;
				}
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
					if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY, i_PosX + x))
					{
						i_Board.m_Cases[i_PosY][i_PosX + x]->SetCaseLight(true, i_Board);
					}
				}
				else
				{
					i_Board.m_Cases[i_PosY][i_PosX + x]->SetVulnerability(true);
				}
			}
			else if (checkRight && i_Board.m_Cases[i_PosY][i_PosX + x]->m_Piece->IsBlack() == IsBlack())
			{
				checkRight = false;

				if (i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY][i_PosX + x]->SetVulnerability(true);
				}
			}
			else if (checkRight && i_Board.m_Cases[i_PosY][i_PosX + x]->m_Piece->IsBlack() != IsBlack())
			{
				checkRight = false;

				if (!i_Vulnerable)
				{
					if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY, i_PosX + x))
					{
						i_Board.m_Cases[i_PosY][i_PosX + x]->SetCaseLight(true, i_Board);
					}
				}
				else
				{
					i_Board.m_Cases[i_PosY][i_PosX + x]->SetVulnerability(true);
				}
			}
		}

		if (i_PosX - x > -1)
		{
			//Look for left direction
			if (checkLeft && (i_Board.m_Cases[i_PosY][i_PosX - x]->m_Piece == nullptr))
			{
				if (!i_Vulnerable)
				{
					if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY, i_PosX - x))
					{
						i_Board.m_Cases[i_PosY][i_PosX - x]->SetCaseLight(true, i_Board);
					}
				}
				else
				{
					i_Board.m_Cases[i_PosY][i_PosX - x]->SetVulnerability(true);
				}
			}
			else if (checkLeft && i_Board.m_Cases[i_PosY][i_PosX - x]->m_Piece->IsBlack() == IsBlack())
			{
				checkLeft = false;

				if (i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY][i_PosX - x]->SetVulnerability(true);
				}
			}
			else if (checkLeft && i_Board.m_Cases[i_PosY][i_PosX - x]->m_Piece->IsBlack() != IsBlack())
			{
				if (!i_Vulnerable)
				{
					if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY, i_PosX - x))
					{
						i_Board.m_Cases[i_PosY][i_PosX - x]->SetCaseLight(true, i_Board);
					}
					checkLeft = false;
				}
				else
				{
					i_Board.m_Cases[i_PosY][i_PosX - x]->SetVulnerability(true);
					checkLeft = false;
				}
			}
		}

		if (i_PosY + x < 8)
		{
			//look for top direction
			if (checkTop && (i_Board.m_Cases[i_PosY + x][i_PosX]->m_Piece == nullptr))
			{
				if (!i_Vulnerable)
				{
					if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY + x, i_PosX))
					{
						i_Board.m_Cases[i_PosY + x][i_PosX]->SetCaseLight(true, i_Board);
					}
				}
				else
				{
					i_Board.m_Cases[i_PosY + x][i_PosX]->SetVulnerability(true);
				}
			}
			else if (checkTop && i_Board.m_Cases[i_PosY + x][i_PosX]->m_Piece->IsBlack() == IsBlack())
			{
				checkTop = false;

				if (i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY + x][i_PosX]->SetVulnerability(true);
				}

			}
			else if (checkTop && i_Board.m_Cases[i_PosY + x][i_PosX]->m_Piece->IsBlack() != IsBlack())
			{
				if (!i_Vulnerable)
				{
					if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY + x, i_PosX))
					{
						i_Board.m_Cases[i_PosY + x][i_PosX]->SetCaseLight(true, i_Board);
					}
					checkTop = false;
				}
				else
				{
					i_Board.m_Cases[i_PosY + x][i_PosX]->SetVulnerability(true);
					checkTop = false;
				}
			}
		}

		if (i_PosY - x > -1)
		{
			//Look for bottom direction
			if (checkBottom && (i_Board.m_Cases[i_PosY - x][i_PosX]->m_Piece == nullptr))
			{
				if (!i_Vulnerable)
				{
					if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY - x, i_PosX))
					{
						i_Board.m_Cases[i_PosY - x][i_PosX]->SetCaseLight(true, i_Board);
					}
				}
				else
				{
					i_Board.m_Cases[i_PosY - x][i_PosX]->SetVulnerability(true);
				}
			}
			else if (checkBottom && i_Board.m_Cases[i_PosY - x][i_PosX]->m_Piece->IsBlack() == IsBlack())
			{
				checkBottom = false;

				if (i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY - x][i_PosX]->SetVulnerability(true);
				}

			}
			else if (checkBottom && i_Board.m_Cases[i_PosY - x][i_PosX]->m_Piece->IsBlack() != IsBlack())
			{
				if (!i_Vulnerable)
				{
					if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY - x, i_PosX))
					{
						i_Board.m_Cases[i_PosY - x][i_PosX]->SetCaseLight(true, i_Board);
					}
					checkBottom = false;
				}
				else
				{
					i_Board.m_Cases[i_PosY - x][i_PosX]->SetVulnerability(true);
					checkBottom = false;
				}
			}
		}
	}
}

bool Dame::IsKingVulnerableAtPos(Board& i_Board, const int& i_PreviousPosY, const int& i_PreviousPosX, const int& i_PosY, const int& i_PosX)
{
	return BasePieces::IsKingVulnerableAtPos(i_Board, i_PreviousPosY, i_PreviousPosX, i_PosY, i_PosX);
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