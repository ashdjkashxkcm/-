#pragma once
#include<iostream>
using namespace std;

//������
class Point
{
public:
	//��������
	void setXY(int x, int y);

	//��ȡ������
	int getX();

	//��ȡ������
	int getY();


private:
	//������
	int m_X;
	//������
	int m_Y;
};
