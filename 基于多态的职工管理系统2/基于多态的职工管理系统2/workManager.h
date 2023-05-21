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
	//���캯��
	workManager();
	
	//��ʾ�˵�
	void showMenu();

	//�˳�ϵͳ
	void exitSystem();

	//��¼Ա������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArry;

	//���ְ��
	void Add_Emp();

	//�����ļ�
	void save();

	//�ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpty;

	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾԱ����Ϣ
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ����
	int IsExist(int id);

	//�޸�ְ����Ϣ
	void Mod_Emp();

	//����ְ��
	void Fin_Emp();

	//���������ְ��
	void Sort_Emp();
	
	//����ļ�
	void Clean_File();

	//��������
	~workManager();
};