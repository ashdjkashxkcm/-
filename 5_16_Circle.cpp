#include"5_16_Circle.h"
#include"5_16_Point.h"



	void Circle::setR(int r)
	{
		m_R = r;
	};
	//��ȡ�뾶
	int Circle::getR()
	{
		return m_R;
	};
	//����Բ��
	void Circle::setCenter(Point c)
	{
		m_Center = c;
	};
	//��ȡԲ��
	Point Circle::getCenter()
	{
		return m_Center;
	};
