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
		cout << "请输入您的选择: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://增加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.Show_Emp();
			break;
		case 3://删除职工
			wm.Del_Emp();
			break;
		case 4://修改职工信息
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Fin_Emp();
			break;
		case 6://根据职工编号排序
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
