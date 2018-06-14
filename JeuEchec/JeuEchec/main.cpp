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

void Save(std::vector<Turn>& iGameTurns);
std::vector<Turn> Load();
void ChangeTurn(const float& i_TimePlayerWhite, const float& i_TimePlayerBlack);


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
	bool TurnPlayerWhite = true;
	Board m_Board = Board();
	BaseCase* selectedPiece = nullptr;
	std::vector<Turn> gameTurns;
	Turn currentTurn;
	clock_t startTime = clock(); //Start timer
	//std::vector<Vector2> ValidMove; 



	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		gameTurns = Load();

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
					Save(gameTurns);
					quit = true;
				}
				if (e.type == SDL_MOUSEBUTTONDOWN)
				{
					if (m_Board.m_Cases[floor(mousePosY / 50)][floor(mousePosX / 50)]->m_Piece != nullptr)
					{
						//validMove = m_Board.m_Cases[floor(mousePosX / 50)][floor(mousePosY / 50)]->m_Piece->VerifMouvLegal();
						selectedPiece = m_Board.m_Cases[floor(mousePosY / 50)][floor(mousePosX / 50)];
						std::cout << "Case X = " << m_Board.m_Cases[floor(mousePosY / 50)][floor(mousePosX / 50)]->PosX << " Y = " << m_Board.m_Cases[floor(mousePosY / 50)][floor(mousePosX / 50)]->PosY << std::endl;
						currentTurn.StartX = floor(mousePosX / 50);
						currentTurn.StartY = floor(mousePosY / 50);
						selectedPiece->m_Piece->LightPossibleMoves(m_Board, floor(mousePosY / 50), floor(mousePosX / 50));
					}
					isButtonDown = true;
				}
				if (e.type == SDL_MOUSEBUTTONUP)
				{
					isButtonDown = false;
				}
				if (e.type == SDL_MOUSEMOTION)
				{
					int x = 0;
					int y = 0;
					SDL_GetMouseState(&mousePosX, &mousePosY);
				}


				
				if (TurnPlayerWhite)
				{
					timePlayerWhite = (clock() - startTime) / 1000;
				}
				else
				{
					timePlayerBlack += (clock() - startTime) / 1000;
				}
				
			}

			//Show mouse position X and Y
			//std::cout << mousePosX << " =X   " << mousePosY << " =Y " << std::endl;
			//Show if ButtonDown
			if (isButtonDown)
			{
				//std::cout << "True" << std::endl;
				if (selectedPiece != nullptr)
				{
					selectedPiece->m_CaseRect.x = mousePosX -25;
					selectedPiece->m_CaseRect.y = mousePosY -25;
				}
				
			}
			else
			{
				if (selectedPiece != nullptr)
				{
					/*
					for (int i = 0; i < validMove.lenght; i++)
					{
						if (validMove[i].x = floor(mousePosX / 50) && validMove[i].y = floor(mousePosY / 50))
						{
							validMove[i]->m_Piece = selectedPiece->m_Piece;
							currentTurn.EndX = floor(mousePosX / 50);
							currentTurn.EndY = floor(mousePosY / 50);
							gameTurns.push_back(currentTurn);
							ChangeTurn(timePlayerWhite, timePlayerBlack);
						}
						else
						{
						*/
							selectedPiece->m_CaseRect.x = selectedPiece->PosX * 50;
							selectedPiece->m_CaseRect.y = selectedPiece->PosY * 50;
							selectedPiece = nullptr;
						/*
						}
					}	
					*/
				}
			}

			//Apply the PNG image
			m_Board.Render(gScreenSurface);


			//Update the surface
			SDL_UpdateWindowSurface(gWindow);
		}
	}
	//Free resources and close SDL
	close();

	return 0;
}

void ChangeTurn(const float& i_TimePlayerWhite,const float& i_TimePlayerBlack)
{
	std::cout << std::fixed;
	std::cout << std::setprecision(0);
	system("cls");
	std::cout << "Time for player White : " << i_TimePlayerWhite << " / Time for player Black :  " << i_TimePlayerBlack << std::endl;
}

void Save(std::vector<Turn>& iGameTurns)
{
	std::ofstream myfile;
	myfile.open("save.txt");
	for each (Turn thisTurn in iGameTurns)
	{
		myfile << thisTurn.StartX << "\n" << thisTurn.StartY << "\n" << thisTurn.EndX << "\n" << thisTurn.EndY << "\n";
	}
	myfile.close();
}

std::vector<Turn> Load()
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
	return gameTurns;
}