#include"employee.h"

Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

void Employee::showInfo()
{
	cout << "Ա����� ��" << this->m_Id
		<< " \tԱ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ����ɾ����õ�����"
		<< endl;
}

string Employee::getDeptName()
{
	return string("Ա��");
}
