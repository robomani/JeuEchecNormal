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
std::vector<Turn> Load(Board& i_Board, bool i_Turn, bool i_Fast);
void ChangeTurn(const float& i_TimePlayerWhite, const float& i_TimePlayerBlack, bool& i_PlayerTurn);
bool Game();

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
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		do
		{

		} while (Game());
	}
	SDL_FreeSurface(gScreenSurface);
	delete gScreenSurface;
	delete gWindow;
	return 0;
}

bool Game()
{
	float timePlayerWhite = 0;
	float timePlayerBlack = 0;
	bool TurnPlayerBlack = false;
	bool gameEnded = false;
	bool m_Check = false;
	Board m_Board = Board();
	std::shared_ptr<BaseCase> selectedPiece = nullptr;
	std::vector<Turn> gameTurns;
	Turn currentTurn;
	clock_t startTime = clock(); //Start timer
	SDL_Surface* m_WinScreen = nullptr;

	//std::vector<Vector2> ValidMove; 



	//Start up SDL and create window
	
		

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
					SDL_FreeSurface(m_WinScreen);
					delete m_WinScreen;
				}
				//Quit en appuillant sur ESC
				if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				{
					Save(gameTurns, TurnPlayerBlack);
					SDL_FreeSurface(m_WinScreen);
					delete m_WinScreen;
					quit = true;
					return false;
				}
				//Restart en apuillant sur R
				if (e.key.keysym.scancode == SDL_SCANCODE_R)
				{
					std::ofstream myfile;
					myfile.open("save.txt", std::ofstream::out | std::ofstream::trunc);
					myfile.close();
					delete m_WinScreen;
					return true;

				}
				//Load en appuillant sur L
				if (e.key.keysym.scancode == SDL_SCANCODE_L)
				{
					gameTurns = Load(m_Board, TurnPlayerBlack, false);

				}
				//Fast foward en apuillant sur F
				if (e.key.keysym.scancode == SDL_SCANCODE_F)
				{
					gameTurns = Load(m_Board, TurnPlayerBlack, true);

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
						if (m_Board.m_Cases[floor(mousePosY / 50)][floor(mousePosX / 50)]->isAlight)
						{
							selectedPiece->PosY = floor(mousePosY / 50);
							selectedPiece->PosX = floor(mousePosX / 50);
							currentTurn.EndX = floor(mousePosX / 50);
							currentTurn.EndY = floor(mousePosY / 50);
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
									if (m_Board.m_Cases[i][x]->m_Piece != nullptr && m_Board.m_Cases[i][x]->m_Piece->IsBlack() == TurnPlayerBlack)
									{
										m_Board.m_Cases[i][x]->m_Piece->LightPossibleMoves(m_Board, i, x, true);
									}
								}

							}

							for (int i = 0; i < m_Board.m_Cases.size(); i++)
							{
								for (int x = 0; x < m_Board.m_Cases[i].size(); x++)
								{
									if (m_Board.m_Cases[i][x]->m_Piece != nullptr && m_Board.m_Cases[i][x]->m_Piece->IsBlack() == TurnPlayerBlack)
									{
										m_Board.m_Cases[i][x]->m_Piece->LightPossibleMoves(m_Board, i, x, false);
										if (m_Board.m_Cases[i][x]->m_Piece->isKing && m_Board.m_Cases[i][x]->isVulnerable)
										{
											m_Check = true;
										}
										if (m_Board.canMove)
										{
											break;
										}
									}
								}
								if (m_Board.canMove)
								{
									break;
								}
							}
							if (!m_Board.canMove)
							{
								if (m_Check)
								{
									if (TurnPlayerBlack)
									{
										m_WinScreen = IMG_Load("ArtWork/PlayerBlackWin.png");
									}
									else
									{
										m_WinScreen = IMG_Load("ArtWork/PlayerWhiteWin.png");
									}								
								}
								else
								{
									m_WinScreen = IMG_Load("ArtWork/Tie.png");
								}
								gameEnded = true;
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
								m_Board.m_Cases[i][x]->SetCaseLight(false, m_Board);
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
				SDL_BlitSurface(m_WinScreen, NULL, gScreenSurface, NULL);
				m_Board.m_Cases[selectedPiece->PosY][selectedPiece->PosX]->Render(gScreenSurface);
				std::cout << "Render";
			}
			//Update the surface
			SDL_UpdateWindowSurface(gWindow);
		}
	
	//Free resources and close SDL
	close();
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
	myfile.open("save.txt", std::ofstream::out | std::ofstream::trunc);
	for each (Turn thisTurn in iGameTurns)
	{
		if (thisTurn.EndY != NULL)
		{
			myfile << thisTurn.StartX << "\n" << thisTurn.StartY << "\n" << thisTurn.EndX << "\n" << thisTurn.EndY << "\n";
		}
	}
	myfile.close();
}

std::vector<Turn> Load(Board& i_Board, bool i_Turn, bool i_Fast)
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

		myfile.open("save.txt", std::ofstream::out | std::ofstream::trunc);
		myfile.close();
		
	}
	
	for each (Turn t in gameTurns)
	{
		i_Board.m_Cases[t.EndY][t.EndX]->m_Piece = i_Board.m_Cases[t.StartY][t.StartX]->m_Piece;
		i_Board.m_Cases[t.EndY][t.EndX]->m_Piece->hasMoved = true;
		i_Board.m_Cases[t.StartY][t.StartX]->m_Piece = nullptr;
		i_Board.Render(gScreenSurface);
		SDL_UpdateWindowSurface(gWindow);
		if (i_Fast)
		{
			SDL_Delay(500);
		}
		else
		{
			SDL_Delay(0);
		}
		i_Turn = !i_Turn;
	}
	return gameTurns;
}