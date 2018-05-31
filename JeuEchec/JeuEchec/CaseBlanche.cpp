#include "CaseBlanche.h"



CaseBlanche::CaseBlanche()
{
	m_ImageBase = SDL_LoadBMP("ArtWork/CaseBlancheBase.bmp");
	m_ImageIlluminer = SDL_LoadBMP("ArtWork/CaseBlancheIlluminer.bmp");
	m_ImageCurrent = m_ImageBase;
}


CaseBlanche::~CaseBlanche()
{
}

