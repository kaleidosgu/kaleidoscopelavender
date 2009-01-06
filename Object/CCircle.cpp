#include "CCircle.h"
#include "../video/VideoDefine.h"
CDrawShape CCircle::m_draw;
CCircle::CCircle(SDL_Surface* screen)
{
	m_nRadius = 0;
	m_pScreen = screen;
	m_bUpdate = true;
	m_bMove   = false;
}
CCircle::~CCircle(void)
{
}
void CCircle::Move()
{
	IObject::Move();
	if( m_bMove )
	{
		m_nY += 3;
		if( m_nY >= SCREEN_HEIGHT)
		{
			m_nY = SCREEN_HEIGHT;
		}
	}
}
void CCircle::Update()
{
	if( m_bUpdate )
	{
		m_nRadius +=2;
	}
}
void CCircle::Init()
{
	m_nRadius = 0;
}
void CCircle::StopUpdate()
{
	m_bUpdate = false;
}
void CCircle::Draw()
{
	int x = 0;
	int y = 0;
	const int backre = m_nRadius;
	for( int q = 0; q < backre; q++)
	{
		for( int i = 0; i < MAX_ANGLE; i++)
		{
			x = q * m_mathConst.getCos(i) + m_nX;
			y = q * m_mathConst.getSin(i) + m_nY;
			if( x >=0 && y >=0 && (x < SCREEN_WIDTH && y < SCREEN_HEIGHT))
			{
				m_draw.DrawPixel(m_pScreen,0,1,1,x,y);
			}
		}
	}
}
void CCircle::StartMove()
{
	m_bMove = true;
}