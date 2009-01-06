#include "IObject.h"
CMath IObject::m_mathConst;
IObject::IObject(void)
{
	m_nX = 0;
	m_nY = 0;
}
IObject::~IObject(void)
{
}
void IObject::Move()
{
}
void IObject::SetPos( int x, int y )
{
	m_nX = x;
	m_nY = y;
}
void IObject::Update()
{
}
void IObject::Init()
{
}
void IObject::Draw()
{
}