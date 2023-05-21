#include"manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

void Manager::showInfo()
{
	cout << "员工编号 ：" << this->m_Id
		<< " \t员工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成老板布置的任务,给员工发布任务"
		<< endl;
}

string Manager::getDeptName()
{
	return string("经理");
}
