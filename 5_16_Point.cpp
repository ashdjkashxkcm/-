#include"5_16_Point.h"

//坐标类

//设置坐标
void Point::setXY(int x, int y)
{
	m_X = x;
	m_Y = y;
}
//获取横坐标
int Point::getX()
{
	return m_X;
}
//获取纵坐标
int Point::getY()
{
	return m_Y;
}
