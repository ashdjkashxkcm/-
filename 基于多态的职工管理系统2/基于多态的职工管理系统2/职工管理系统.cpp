#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include"workManager.h"

int main()
{	
	workManager wm;
	int choice;

	while (true)
	{
		wm.showMenu();
		cout << "����������ѡ��: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1://����ְ��
			wm.Add_Emp();
			break;
		case 2://��ʾְ��
			wm.Show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4://�޸�ְ����Ϣ
			wm.Mod_Emp();
			break;
		case 5://����ְ��
			wm.Fin_Emp();
			break;
		case 6://����ְ���������
			wm.Sort_Emp();
			break;
		case 7:
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
