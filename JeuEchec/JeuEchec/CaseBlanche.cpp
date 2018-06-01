#include "CaseBlanche.h"



CaseBlanche::CaseBlanche()
{
	m_ImageBase = loadSurface("ArtWork/CaseBlancheBase.bmp");
	m_ImageIlluminer = loadSurface("ArtWork/CaseBlancheIlluminer.bmp");
	m_ImageCurrent = m_ImageBase;
}


CaseBlanche::~CaseBlanche()
{
}

