#include"5_16_Circle.h"
#include"5_16_Point.h"



	void Circle::setR(int r)
	{
		m_R = r;
	};
	//获取半径
	int Circle::getR()
	{
		return m_R;
	};
	//设置圆心
	void Circle::setCenter(Point c)
	{
		m_Center = c;
	};
	//获取圆心
	Point Circle::getCenter()
	{
		return m_Center;
	};
