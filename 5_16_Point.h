#pragma once
#include<iostream>
using namespace std;

//坐标类
class Point
{
public:
	//设置坐标
	void setXY(int x, int y);

	//获取横坐标
	int getX();

	//获取纵坐标
	int getY();


private:
	//横坐标
	int m_X;
	//纵坐标
	int m_Y;
};
