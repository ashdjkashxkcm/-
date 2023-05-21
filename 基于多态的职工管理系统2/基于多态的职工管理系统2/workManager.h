#pragma once
#include<iostream>
#include<fstream>

using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#define FILENAME "empFile.txt"

class workManager
{
public:
	//构造函数
	workManager();
	
	//显示菜单
	void showMenu();

	//退出系统
	void exitSystem();

	//记录员工数量
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArry;

	//添加职工
	void Add_Emp();

	//保存文件
	void save();

	//文件是否为空的标志
	bool m_FileIsEmpty;

	//统计文件中人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示员工信息
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//判度职工是否存在
	int IsExist(int id);

	//修改职工信息
	void Mod_Emp();

	//查找职工
	void Fin_Emp();

	//按序号排序职工
	void Sort_Emp();
	
	//清空文件
	void Clean_File();

	//析构函数
	~workManager();
};