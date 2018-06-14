#include "Board.h"
#include "Cavalier.h"
#include "Dame.h"
#include "Fou.h"
#include "Pion.h"
#include "Roi.h"
#include "Tour.h"
#include "BaseCase.h"
#include <vector>


Board::Board()
{
	m_BoardSurface = IMG_Load("ArtWork/Chessboard400.png");	
	initialisation();
}


Board::~Board()
{
	for each (std::vector<BaseCase*> vectorOfVector in m_Cases)
	{
		for each (BaseCase* pointerOfBaseCase in vectorOfVector)
		{
			if (pointerOfBaseCase->m_Piece != nullptr)
			{
				delete pointerOfBaseCase->m_Piece;
				pointerOfBaseCase->m_Piece = nullptr;
			}
			delete pointerOfBaseCase;
			pointerOfBaseCase = nullptr;
		}
	}
}


void Board::initialisation()
{
	for (int i = 0; i < 8; i++)
	{
		m_Cases.push_back(std::vector<BaseCase*>());
		for (int x = 0; x < 8; x++)
		{
			if (i ==0 || i == 7)
			{
				switch (x)
				{
				case 0:
					m_Cases[i].push_back(new BaseCase(x, i, new Tour(i, x, i)));
					break;
				case 1:
					m_Cases[i].push_back(new BaseCase(x, i, new Cavalier(i, x, i)));
					break;
				case 2:
					m_Cases[i].push_back(new BaseCase(x, i, new Fou(i, x, i)));
					break;
				case 3:
					m_Cases[i].push_back(new BaseCase(x, i, new Dame(i, x, i)));
					break;
				case 4:
					m_Cases[i].push_back(new BaseCase(x, i, new Roi(i, x, i)));
					break;
				case 5:
					m_Cases[i].push_back(new BaseCase(x, i, new Fou(i, x, i)));
					break;
				case 6:
					m_Cases[i].push_back(new BaseCase(x, i, new Cavalier(i, x, i)));
					break;
				case 7:
					m_Cases[i].push_back(new BaseCase(x, i, new Tour(i, x, i)));
					break;
				default:
					m_Cases[i].push_back(new BaseCase(x - 8, (i * 5) + 1, new Pion(i, x - 8, (i * 5) + 1)));
					break;
				}
			}
			else if(i == 1)
			{
				m_Cases[i].push_back(new BaseCase(x, i, new Pion(0, x,i)));
			}
			else if (i == 6)
			{
				m_Cases[i].push_back(new BaseCase(x, i, new Pion(1, x, i)));
			}
			else
			{
				m_Cases[i].push_back(new BaseCase(x, i));
			}
		}
	}
}

void Board::Render(SDL_Surface* gScreenSurface)
{
	SDL_BlitSurface(m_BoardSurface, NULL, gScreenSurface, NULL);
	for (int i = 0; i < m_Cases.size(); i++)
	{
		for (int x = 0; x < m_Cases[i].size(); x++)
		{
			m_Cases[i][x]->Render(gScreenSurface);
		}
	}
}
