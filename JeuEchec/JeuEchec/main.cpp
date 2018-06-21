/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <iostream>
#include "Board.h"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "Turn.h"

//Screen dimension constants
const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 400;

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

void Save(const std::vector<Turn>& iGameTurns, const bool i_Turn);
std::vector<Turn> Load(Board& i_Board, bool& i_Turn);
void ChangeTurn(const float& i_TimePlayerWhite, const float& i_TimePlayerBlack, bool& i_PlayerTurn);


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface(gWindow);
				SDL_WarpMouseInWindow(gWindow, 200, 200);


			}
		}
	}

	return success;
}



void close()
{
	//Free loaded image
	//SDL_FreeSurface(gPNGSurface);
	//gPNGSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* loadSurface(std::string path)
{
	return IMG_Load(path.c_str());
}

int main(int argc, char* args[])
{
	float timePlayerWhite = 0;
	float timePlayerBlack = 0;
	bool TurnPlayerBlack = false;
	bool gameEnded = false;
	Board m_Board = Board();
	BaseCase* selectedPiece = nullptr;
	std::vector<Turn> gameTurns;
	Turn currentTurn;
	clock_t startTime = clock(); //Start timer
	SDL_Surface* m_WinScreen = nullptr;

	//std::vector<Vector2> ValidMove; 

	

	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		gameTurns = Load(m_Board, TurnPlayerBlack);

		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		bool isButtonDown = false;
		int mousePosX = 0;
		int mousePosY = 0;

		//While application is running
		while (!quit)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					Save(gameTurns, TurnPlayerBlack);
					quit = true;
				}
				if (e.type == SDL_KEYDOWN)
				{
					Save(gameTurns, TurnPlayerBlack);
					delete selectedPiece;
					quit = true;
				}
				if (e.type == SDL_MOUSEBUTTONDOWN)
				{
					if (m_Board.m_Cases[floor(mousePosY / 50)][floor(mousePosX / 50)]->m_Piece != nullptr && m_Board.m_Cases[floor(mousePosY / 50)][floor(mousePosX / 50)]->m_Piece->IsBlack() == TurnPlayerBlack)
					{
						selectedPiece = m_Board.m_Cases[floor(mousePosY / 50)][floor(mousePosX / 50)];
						std::cout << "Case X = " << m_Board.m_Cases[floor(mousePosY / 50)][floor(mousePosX / 50)]->PosX << " Y = " << m_Board.m_Cases[floor(mousePosY / 50)][floor(mousePosX / 50)]->PosY << std::endl;
						currentTurn.StartX = floor(mousePosX / 50);
						currentTurn.StartY = floor(mousePosY / 50);
						selectedPiece->m_Piece->LightPossibleMoves(m_Board, floor(mousePosY / 50), floor(mousePosX / 50), false);
					}
					isButtonDown = true;
				}
				if (e.type == SDL_MOUSEBUTTONUP)
				{
					isButtonDown = false;

					if (selectedPiece != nullptr)
					{
						if (mousePosY >= 400 || mousePosX >= 400)
						{


						}
						if (m_Board.m_Cases[floor(mousePosY / 50)][floor(mousePosX / 50)]->isAlight)
						{
							selectedPiece->PosY = floor(mousePosY / 50);
							selectedPiece->PosX = floor(mousePosX / 50);
							currentTurn.EndX = floor(mousePosX / 50);
							currentTurn.EndY = floor(mousePosY / 50);
							if (m_Board.m_Cases[currentTurn.EndY][currentTurn.EndX]->m_Piece)
							{
								if (m_Board.m_Cases[currentTurn.EndY][currentTurn.EndX]->m_Piece->isKing)
								{
									if (TurnPlayerBlack)
									{
										m_WinScreen = IMG_Load("ArtWork/PlayerBlackWin.png");
									}
									else
									{
										m_WinScreen = IMG_Load("ArtWork/PlayerWhiteWin.png");
									}
									gameEnded = true;
								}
								delete m_Board.m_Cases[currentTurn.EndY][currentTurn.EndX]->m_Piece;
							}
							m_Board.m_Cases[currentTurn.EndY][currentTurn.EndX]->m_Piece = selectedPiece->m_Piece;
							selectedPiece->m_Piece->hasMoved = true;
							m_Board.m_Cases[currentTurn.StartY][currentTurn.StartX]->m_Piece = nullptr;
							gameTurns.push_back(currentTurn);
							selectedPiece->m_CaseRect.x = currentTurn.StartX * 50;
							selectedPiece->m_CaseRect.y = currentTurn.StartY * 50;
							selectedPiece = nullptr;
							ChangeTurn(timePlayerWhite, timePlayerBlack, TurnPlayerBlack);
							for (int i = 0; i < m_Board.m_Cases.size(); i++)
							{
								for (int x = 0; x < m_Board.m_Cases[i].size(); x++)
								{
									m_Board.m_Cases[i][x]->SetVulnerability(false);
								}

							}

							for (int i = 0; i < m_Board.m_Cases.size(); i++)
							{
								for (int x = 0; x < m_Board.m_Cases[i].size(); x++)
								{
									if (m_Board.m_Cases[i][x]->m_Piece != nullptr && m_Board.m_Cases[i][x]->m_Piece->IsBlack() != TurnPlayerBlack)
									{
										m_Board.m_Cases[i][x]->m_Piece->LightPossibleMoves(m_Board, i, x, true);
									}
								}

							}
						}
						else
						{

							selectedPiece->m_CaseRect.x = selectedPiece->PosX * 50;
							selectedPiece->m_CaseRect.y = selectedPiece->PosY * 50;
							selectedPiece = nullptr;
						}

						for (int i = 0; i < m_Board.m_Cases.size(); i++)
						{
							for (int x = 0; x < m_Board.m_Cases[i].size(); x++)
							{
								m_Board.m_Cases[i][x]->SetCaseLight(false);
							}
						}
					}
				}
				if (e.type == SDL_MOUSEMOTION)
				{
					int x = 0;
					int y = 0;
					SDL_GetMouseState(&mousePosX, &mousePosY);
					if (mousePosX < 0 || mousePosX > 400 || mousePosY < 0 || mousePosY > 400)
					{
						SDL_WarpMouseInWindow(gWindow, 200, 200);
					}
				}



				if (!TurnPlayerBlack)
				{
					timePlayerWhite = (clock() - startTime) / 1000;
				}
				else
				{
					timePlayerBlack = (clock() - startTime) / 1000;
				}

			}

			//Show mouse position X and Y
			//std::cout << mousePosX << " =X   " << mousePosY << " =Y " << std::endl;
			//Show if ButtonDown
			if (isButtonDown)
			{
				//std::cout << "True" << std::endl;
				if (mousePosY < 400 - 25 && mousePosX < 400 - 25 && selectedPiece != nullptr)
				{
					selectedPiece->m_CaseRect.x = mousePosX - 25;
					selectedPiece->m_CaseRect.y = mousePosY - 25;
				}

			}
			else
			{

			}
			//Apply the PNG image
			if (!gameEnded)
			{
				m_Board.Render(gScreenSurface);
				if (selectedPiece != nullptr)
				{
					m_Board.m_Cases[selectedPiece->PosY][selectedPiece->PosX]->Render(gScreenSurface);
				}
			}
			else
			{
<<<<<<< HEAD
				SDL_BlitSurface(m_WinScreen, NULL, gScreenSurface, NULL);
=======
				m_Board.m_Cases[selectedPiece->PosY][selectedPiece->PosX]->Render(gScreenSurface);
				std::cout << "Render";
>>>>>>> remotes/origin/master
			}
			//Update the surface
			SDL_UpdateWindowSurface(gWindow);
		}
	}
	//Free resources and close SDL
	close();

	return 0;
}

void ChangeTurn(const float& i_TimePlayerWhite,const float& i_TimePlayerBlack, bool& i_PlayerTurn)
{
	i_PlayerTurn = !i_PlayerTurn;
	std::cout << std::fixed;
	std::cout << std::setprecision(0);
	system("cls");
	std::cout << "Time for player White : " << i_TimePlayerWhite << " / Time for player Black :  " << i_TimePlayerBlack << std::endl;
}

void Save(const std::vector<Turn>& iGameTurns ,const bool i_Turn)
{
	std::ofstream myfile;
	myfile.open("save.txt");
	for each (Turn thisTurn in iGameTurns)
	{
		if (thisTurn.EndY != NULL)
		{
			myfile << thisTurn.StartX << "\n" << thisTurn.StartY << "\n" << thisTurn.EndX << "\n" << thisTurn.EndY << "\n";
		}
	}
	myfile.close();
}

std::vector<Turn> Load(Board& i_Board, bool& i_Turn)
{
	std::vector<Turn> gameTurns;
	Turn currentTurn;
	std::string line;
	std::ifstream myfile;
	myfile.open("save.txt");


	if (myfile.is_open())
	{
		int i = 0;
		
		while (getline(myfile, line))
		{
			switch (i)
			{
			case 0:
				currentTurn.StartX = atoi(line.c_str());
				i++;
				break;
			case 1:
				currentTurn.StartY = atoi(line.c_str());
				i++;
				break;
			case 2:
				currentTurn.EndX = atoi(line.c_str());
				i++;
				break;
			case 3:
				currentTurn.EndY = atoi(line.c_str());
				gameTurns.push_back(currentTurn);
				i = 0;
				break;
			default:
			break;
			}	
		}
		myfile.close();
		
	}
	
	for each (Turn t in gameTurns)
	{
		if (i_Board.m_Cases[t.EndY][t.EndX]->m_Piece)
		{
			delete i_Board.m_Cases[t.EndY][t.EndX]->m_Piece;
		}
		i_Board.m_Cases[t.EndY][t.EndX]->m_Piece = i_Board.m_Cases[t.StartY][t.StartX]->m_Piece;
		i_Board.m_Cases[t.EndY][t.EndX]->m_Piece->hasMoved = true;
		i_Board.m_Cases[t.StartY][t.StartX]->m_Piece = nullptr;
		i_Board.Render(gScreenSurface);
		SDL_UpdateWindowSurface(gWindow);
		SDL_Delay(1000);
		i_Turn = !i_Turn;
	}
	return gameTurns;
}