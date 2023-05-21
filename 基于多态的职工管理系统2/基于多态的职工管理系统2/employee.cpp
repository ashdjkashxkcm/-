#include"employee.h"

Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

void Employee::showInfo()
{
	cout << "员工编号 ：" << this->m_Id
		<< " \t员工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成经理布置的任务"
		<< endl;
}

string Employee::getDeptName()
{
	return string("员工");
}
