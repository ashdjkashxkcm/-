#pragma once
#include<iostream>
using namespace std;
#include"5_16_Point.h"

//Բ��
class Circle
{
public:
	//���ð뾶
	void setR(int r);

	//��ȡ�뾶
	int getR();

	//����Բ��
	void setCenter(Point c);

	//��ȡԲ��
	Point getCenter();


private:
	//�뾶
	int m_R;
	//Բ��
	Point m_Center;
};