#include"boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

void Boss::showInfo()
{
	cout << "员工编号 ：" << this->m_Id
		<< " \t员工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：处理公司事务"
		<< endl;
}

string Boss::getDeptName()
{
	return string("老板");
}
