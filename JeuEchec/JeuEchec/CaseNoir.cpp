#include "CaseNoir.h"



CaseNoir::CaseNoir()
{
	m_ImageBase = loadSurface("ArtWork/CaseNoirBase.bmp");
	m_ImageIlluminer = loadSurface("ArtWork/CaseNoirIlluminer.bmp");
	m_ImageCurrent = m_ImageBase;
}


CaseNoir::~CaseNoir()
{
}


