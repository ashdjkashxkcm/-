#include<iostream>
using namespace std;
#include<string>
#define MAX  1000

//�����ϵ�˽ṹ��
struct Person
{
	//����
	string m_Name;
	//�Ա�
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;
};
//���ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];

	//ͨѶ¼�е�ǰ��¼
	int m_Size;
};

void addPerson(Addressbooks * abs)
{
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else
	{
		//�����ϵ��

		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		cout << "�������Ա� " << endl;
		cout << "1 ---- ��" << endl;
		cout << "2 ---- Ů" << endl;
		int sex = 0;
		
		while (true)
		{	
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "��������룺" << endl;
		}

		//����
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//�绰
		string phone;
		cout << "������绰���룺" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//סַ
		string addr;
		cout << "�������ַ��" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		//����ͨѶ¼�е�����
		abs->m_Size++;

		cout << "��ӳɹ�" << endl;
		system("pause");//�밴���������
		system("cls");//����
	}
}

//��ʾ��ϵ��
void showPerson(Addressbooks * abs) 
{	
	if (abs ->m_Size ==0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������ " << abs->personArray[i].m_Name << "\t"
				<< "�Ա� " << (abs->personArray[i].m_Sex == 1 ? "��":"Ů") << "\t"  //��Ŀ����� �ж������Ů
				<< "���䣺 " << abs->personArray[i].m_Age << "\t"
				<< "�绰�ţ� " << abs->personArray[i].m_Phone << "\t"
				<< "סַ�� " << abs->personArray[i].m_Addr << "\t" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���� ��������ڣ�������ϵ�����������еľ���λ�� �����ڷ���-1
int isExist(Addressbooks * abs,string name)
{	
	for (int i = 0; i < abs->m_Size;i++) 
	{	
		
		if (abs ->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

//ɾ����ϵ��
void deletePerson(Addressbooks * abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	
	int ret = isExist(abs,name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--; //����ͨѶ¼�е���Ա��
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//������ϵ��
void findPerson(Addressbooks * abs)
{
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret1 = isExist(abs, name);
	if (ret1 != -1) 
	{
		cout << "������ " << abs->personArray[ret1].m_Name << "\t"
			<< "�Ա� " << (abs->personArray[ret1].m_Sex == 1 ? "��" : "Ů") << "\t"  //��Ŀ����� �ж������Ů
			<< "���䣺 " << abs->personArray[ret1].m_Age << "\t"
			<< "�绰�ţ� " << abs->personArray[ret1].m_Phone << "\t"
			<< "סַ�� " << abs->personArray[ret1].m_Addr << "\t" << endl;
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifyPerson(Addressbooks * abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//�Ա�
		cout << "�������Ա� " << endl;
		cout << "1 ---- ��" << endl;
		cout << "2 ---- Ů" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "��������룺" << endl;
		}

		//����
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//�绰
		string phone;
		cout << "������绰���룺" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//סַ
		string addr;
		cout << "�������ַ��" << endl;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;

		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	
	system("pause");
	system("cls");
}

//�����ϵ��
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	
	system("pause");
	system("cls");
}

//�˵�����
void showMenu()
{	
	cout << "**********************" << endl;
	cout << "**** 1.�����ϵ�� ****" << endl;
	cout << "**** 2.��ʾ��ϵ�� ****" << endl;
	cout << "**** 3.ɾ����ϵ�� ****" << endl;
	cout << "**** 4.������ϵ�� ****" << endl;
	cout << "**** 5.�޸���ϵ�� ****" << endl;
	cout << "**** 6.�����ϵ�� ****" << endl;
	cout << "**** 0.�˳�ͨѶ¼ ****" << endl;
	cout << "**********************" << endl;
}

int main()
{	
	//�����ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼��ǰ��Ա����
	abs.m_Size = 0;
	
	int select = 0;

	while (true)
	{
		showMenu();
		cin >> select;

		switch (select)
		{
		case 1:  //1.�����ϵ��
			addPerson(&abs);//���õ�ַ���ݣ������޸�ʵ��
			break;
		case 2: //2.��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3: //3.ɾ����ϵ��
		{
			deletePerson(&abs);
			break;
		}
		case 4: //4.������ϵ��
			findPerson(&abs);
			break;
		case 5: //5.�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6: //6.�����ϵ��
		{	
			cout << "�Ƿ����Ҫ���������ϵ��" << endl;
			cout << "1 ---- ȷ��" << endl;
			cout << "2 ---- ȡ��" << endl;
			int rrr = 0;
			cin >> rrr;
			if (rrr == 1) 
			{
				cleanPerson(&abs);
			}
			else
			{
				cout << "ȡ������" << endl;
				system("pause");
				system("cls");
			}
			break;
		}
		case 0: //0.�˳�ͨѶ¼
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}