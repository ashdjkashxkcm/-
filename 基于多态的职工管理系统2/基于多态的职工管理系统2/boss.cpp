#include"boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

void Boss::showInfo()
{
	cout << "Ա����� ��" << this->m_Id
		<< " \tԱ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ�𣺴���˾����"
		<< endl;
}

string Boss::getDeptName()
{
	return string("�ϰ�");
}
