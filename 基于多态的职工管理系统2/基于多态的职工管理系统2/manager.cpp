#include"manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

void Manager::showInfo()
{
	cout << "Ա����� ��" << this->m_Id
		<< " \tԱ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ������ϰ岼�õ�����,��Ա����������"
		<< endl;
}

string Manager::getDeptName()
{
	return string("����");
}
