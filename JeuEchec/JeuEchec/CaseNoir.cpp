#include "CaseNoir.h"



CaseNoir::CaseNoir()
{
	m_ImageBase = SDL_LoadBMP("ArtWork/CaseNoirBase.bmp");
	m_ImageIlluminer = SDL_LoadBMP("ArtWork/CaseNoirIlluminer.bmp");
	m_ImageCurrent = m_ImageBase;
}


CaseNoir::~CaseNoir()
{
}


