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
	SDL_FreeSurface(m_BoardSurface);
	delete(m_BoardSurface);
}


void Board::initialisation()
{
	for (int i = 0; i < 8; i++)
	{
		m_Cases.push_back(std::vector<std::shared_ptr<BaseCase>>());
		for (int x = 0; x < 8; x++)
		{
			if (i == 0 || i == 7)
			{
				switch (x)
				{
				case 0:
					m_Cases[i].push_back(std::make_shared<BaseCase>(x, i, std::make_shared<Tour>(i)));
					break;
				case 1:
					m_Cases[i].push_back(std::make_shared<BaseCase>(x, i, std::make_shared<Cavalier>(i)));
					break;
				case 2:
					m_Cases[i].push_back(std::make_shared<BaseCase>(x, i, std::make_shared<Fou>(i)));
					break;
				case 3:
					m_Cases[i].push_back(std::make_shared<BaseCase>(x, i, std::make_shared<Dame>(i)));
					break;
				case 4:
					m_Cases[i].push_back(std::make_shared<BaseCase>(x, i, std::make_shared<Roi>(i)));
					break;
				case 5:
					m_Cases[i].push_back(std::make_shared<BaseCase>(x, i, std::make_shared<Fou>(i)));
					break;
				case 6:
					m_Cases[i].push_back(std::make_shared<BaseCase>(x, i, std::make_shared<Cavalier>(i)));
					break;
				case 7:
					m_Cases[i].push_back(std::make_shared<BaseCase>(x, i, std::make_shared<Tour>(i)));
					break;
				}
			}
			else if (i == 1)
			{
				m_Cases[i].push_back(std::make_shared<BaseCase>(x, i, std::make_shared<Pion>(0)));
			}
			else if (i == 6)
			{
				m_Cases[i].push_back(std::make_shared<BaseCase>(x, i, std::make_shared<Pion>(1)));
			}
			else
			{
				m_Cases[i].push_back(std::make_shared<BaseCase>(x, i));
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
