#include "CCircle.h"
#include "../video/VideoDefine.h"
CDrawShape CCircle::draw;
CCircle::CCircle(void)
{
	m_nRadius = 0;
}
CCircle::~CCircle(void)
{
}
void CCircle::Move()
{
	IObject::Move();
	m_nY += 3;
	if( m_nY >= SCREEN_HEIGHT)
	{
		m_nY = SCREEN_HEIGHT;
	}
}
void CCircle::Update()
{
	m_nRadius +=2;
}
void CCircle::Init()
{
	m_nRadius = 0;
}
void Draw()
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
				DrawPixel(screen,R,G,B,x,y);
			}
		}
	}
}