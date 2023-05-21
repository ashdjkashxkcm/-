#include"workManager.h"

workManager::workManager()
{
	ifstream ofs;
	ofs.open(FILENAME, ios::in);

	//1.�ļ�������
	if (!ofs.is_open())
	{
		//cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;//��ʼ������
		this->m_EmpArry = NULL;//��ʼ������ָ��
		this->m_FileIsEmpty = true;//��ʼ�ļ�Ϊ�ձ�־
		ofs.close();
		return;
	}

	//2.�ļ����ڣ�������Ϊ��
	char ch;
	ofs >> ch;
	if (ofs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;//��ʼ������
		this->m_EmpArry = NULL;//��ʼ������ָ��
		this->m_FileIsEmpty = true;//��ʼ�ļ�Ϊ�ձ�־
		ofs.close();
		return;
	}

	//3.�ļ����ڣ����Ҽ�¼������
	this->m_EmpNum = this->get_EmpNum();
	//cout << "ְ��������Ϊ��" << this->m_EmpNum << endl;

	this->m_EmpArry = new Worker * [this->m_EmpNum];
	this->init_Emp();


}

void workManager::showMenu()
{
	cout << "**********************************" << endl;
	cout << "****** ��ӭʹ��ְ������ϵͳ ******" << endl;
	cout << "******    0.�˳��������    ******" << endl;
	cout << "******    1.����ְ����Ϣ    ******" << endl;
	cout << "******    2.��ʾְ����Ϣ    ******" << endl;
	cout << "******    3.ɾ��ְ����Ϣ    ******" << endl;
	cout << "******    4.�޸�ְ����Ϣ    ******" << endl;
	cout << "******    5.����ְ����Ϣ    ******" << endl;
	cout << "******    6.���ձ������    ******" << endl;
	cout << "******    7.��������ĵ�    ******" << endl;
	cout << "**********************************" << endl;
	cout << endl;
}

void workManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void workManager::Add_Emp()
{
	cout << "��������Ҫ��ӵ�ְ������:" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//���
		//�����¿��ٿռ��С
		int newSize = this->m_EmpNum + addNum;
		//�����¿ռ�
		Worker** newSpace = new Worker* [newSize];

		//��ԭ����������ӵ��¿ռ�
		if (this->m_EmpArry != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArry[i];
			}
		}
		
		//�����Ա��
		for (int i = 0; i < addNum; i++)
		{
			int id = 0;
			string name;
			int dSelect;

			cout << "�������" << i + 1 << "��Ա�����" << endl;
			while (true)
			{	
				cin >> id;
				int j = 0;
				for ( j; j < this->m_EmpNum; j++)
				{
					if (this->m_EmpArry[j]->m_Id == id)
					{
						cout << "����ְ������ظ�������������" << endl;
						break;
					}
				}
				if (j == this->m_EmpNum)
				{
					break;
				}
			}
			cout << "�������" << i + 1 << "��Ա������" << endl;
			cin >> name;

			cout << "��ѡ���" << i + 1 << "��Ա��ְλ" << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;

			switch (dSelect)
			{
			case 1:
				worker = new Employee(id,name,1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
			case 3:
				worker = new Boss(id, name, 3);
			default:
				break;
			}

			//��Ա�����浽����
			newSpace[this->m_EmpNum + i] = worker;

		}
		//���ԭ������
		delete[] this->m_EmpArry;

		//����Ա������
		this->m_EmpArry = newSpace;

		//����Ա������
		this->m_EmpNum = newSize;

		//�����ļ���־ Ϊ ��Ϊ��
		this->m_FileIsEmpty = false;

		cout << "�ɹ����" << addNum << "��ְ��" << endl;

		this->save();
	}
	else
	{
		cout << "�������" << endl;
	}

	system("pause");
	system("cls");
}

void workManager::save()
{
	ofstream ofs;

	ofs.open(FILENAME, ios::out);

	//д�ļ�
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArry[i]->m_Id << " "
			<< this->m_EmpArry[i]->m_Name << " "
			<< this->m_EmpArry[i]->m_Did << " "
			<< endl;
	}
	//�ر��ļ�
	ofs.close();

}

int workManager::get_EmpNum()
{
	ifstream ofd;
	ofd.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int num = 0;
	while (ofd >> id && ofd >> name && ofd >> did)
	{
		num++;
	}
	ofd.close();

	return num;
}

void workManager::init_Emp()
{
	ifstream ofd;
	ofd.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int index = 0;
	while (ofd >> id && ofd >> name && ofd >> did)
	{
		Worker* worker = NULL;
		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		if (did == 3)
		{
			worker = new Boss(id, name, did);
		}

		this->m_EmpArry[index++] = worker;
	}
}

void workManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{ 
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArry[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//ɾ��ְ��
void workManager::Del_Emp()
{	
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�� " << endl;
	}
	else
	{
		int id;
		cout << "������Ҫɾ��Ա�����: " << endl;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArry[i] = this->m_EmpArry[i + 1];
			}
			this->m_EmpNum--;

			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "��ְ��������" << endl;
		}
	}
	system("pause");
	system("cls");
}


//�ж�ְ���Ƿ����
int workManager::IsExist(int id)
{
	int dex = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArry[i]->m_Id == id)
		{
			dex = i;
			break;
		}
	}
	return dex;
}

void workManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << " �ļ������ڻ�����Ϊ�� " << endl;
	}
	else
	{
		int id;
		string name;
		int dSelect;

		cout << "������Ҫ�޸ĵ�ְ�����" << endl;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1)
		{	
			delete this->m_EmpArry[index];

			cout << "�������µ�Ա�����" << endl;
			while (true)
			{
				cin >> id;
				int j = 0;
				for (j; j < this->m_EmpNum; j++)
				{
					if (this->m_EmpArry[j]->m_Id == id)
					{
						cout << "����ְ������ظ�������������" << endl;
						break;
					}
				}
				if (j == this->m_EmpNum)
				{
					break;
				}
			}
			cout << "�������µ�ְ������" << endl;
			cin >> name;
			cout << "��ѡ���µ�ְ��ְλ" << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			
			Worker* worker = NULL;

			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}
			//������Ϣ
			this->m_EmpArry[index] = worker;
			//�����ݱ��浽�ļ���
			this->save();
		}
		else
		{
			cout << "��ְ��������" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workManager::Fin_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�����Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ����ҷ�ʽ: " << endl;
		cout << "1.��ְ����Ž��в���" << endl;
		cout << "2.��ְ���������в���" << endl;
		int select;
		cin >> select;

		switch (select)
		{
		case 1:
		{
			cout << "������Ҫ����ְ�����" << endl;
			int id;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArry[ret]->showInfo();
			}
			else
			{
				cout << "���޴���" << endl;
			}
			break;
		}
		case 2:
		{
			cout << "������Ҫ����ְ������" << endl;
			string name;

			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArry[i]->m_Name == name)
				{
					cout << "���ҳɹ�,���Ϊ" << this->m_EmpArry[i]->m_Id << "ְ����Ϣ����" << endl;
					this->m_EmpArry[i]->showInfo();
					flag = true;
				}
			}
			if (flag)
			{
				cout << "���޴���" << endl;
			}
		}
		default:
			cout << "��������" << endl;
			break;
		}

	}
}

void workManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�����Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1.������ʽ����" << endl;
		cout << "2,������ʽ����" << endl;
		int Select;
		cin >> Select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i+1; j < m_EmpNum; j++)
			{
				if (Select == 1)
				{
					if (this->m_EmpArry[minOrMax]->m_Id > this->m_EmpArry[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					if (this->m_EmpArry[minOrMax]->m_Id < this->m_EmpArry[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArry[i];
				this->m_EmpArry[i] = this->m_EmpArry[minOrMax];
				this->m_EmpArry[minOrMax] = temp;
			}
		}
		cout << "����ɹ�,������Ϊ" << endl;
		this->save();
		this->Show_Emp();
	}
}

void workManager::Clean_File()
{
	cout << "�Ƿ�ȷ������ļ�" << endl;
	cout << "1,ȷ��" << endl;
	cout << "2.ȡ��" << endl;
	int Select;
	cin >> Select;

	if (Select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//����ļ������´����ļ�
		ofs.close();

		if (this->m_EmpArry != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArry[i];
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArry;
			this->m_EmpArry = NULL;
			this->m_FileIsEmpty = true;
		}
	}
	system("pause");
	system("cls");
}


workManager::~workManager() 
{	
	if (this->m_EmpArry != NULL)
	{
		delete[] this->m_EmpArry;
		this->m_EmpArry = NULL;
	}
}