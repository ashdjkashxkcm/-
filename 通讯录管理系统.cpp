#include<iostream>
using namespace std;
#include<string>
#define MAX  1000

//设计联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};
//设计通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];

	//通讯录中当前记录
	int m_Size;
};

void addPerson(Addressbooks * abs)
{
	//判断通讯录是否已满，如果满了就不再添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	else
	{
		//添加联系人

		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		cout << "请输入性别： " << endl;
		cout << "1 ---- 男" << endl;
		cout << "2 ---- 女" << endl;
		int sex = 0;
		
		while (true)
		{	
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "请从新输入：" << endl;
		}

		//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		string phone;
		cout << "请输入电话号码：" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		string addr;
		cout << "请输入地址：" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		//更新通讯录中的人数
		abs->m_Size++;

		cout << "添加成功" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏
	}
}

//显示联系人
void showPerson(Addressbooks * abs) 
{	
	if (abs ->m_Size ==0)
	{
		cout << "通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名： " << abs->personArray[i].m_Name << "\t"
				<< "性别： " << (abs->personArray[i].m_Sex == 1 ? "男":"女") << "\t"  //三目运算符 判断输出男女
				<< "年龄： " << abs->personArray[i].m_Age << "\t"
				<< "电话号： " << abs->personArray[i].m_Phone << "\t"
				<< "住址： " << abs->personArray[i].m_Addr << "\t" << endl;
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在 ，如果存在，返回联系人所在数组中的具体位置 不存在返回-1
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

//删除联系人
void deletePerson(Addressbooks * abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	
	int ret = isExist(abs,name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--; //更新通讯录中的人员数
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void findPerson(Addressbooks * abs)
{
	cout << "请输入要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret1 = isExist(abs, name);
	if (ret1 != -1) 
	{
		cout << "姓名： " << abs->personArray[ret1].m_Name << "\t"
			<< "性别： " << (abs->personArray[ret1].m_Sex == 1 ? "男" : "女") << "\t"  //三目运算符 判断输出男女
			<< "年龄： " << abs->personArray[ret1].m_Age << "\t"
			<< "电话号： " << abs->personArray[ret1].m_Phone << "\t"
			<< "住址： " << abs->personArray[ret1].m_Addr << "\t" << endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void modifyPerson(Addressbooks * abs)
{
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//性别
		cout << "请输入性别： " << endl;
		cout << "1 ---- 男" << endl;
		cout << "2 ---- 女" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "请从新输入：" << endl;
		}

		//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//电话
		string phone;
		cout << "请输入电话号码：" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//住址
		string addr;
		cout << "请输入地址：" << endl;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;

		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	
	system("pause");
	system("cls");
}

//清空联系人
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	
	system("pause");
	system("cls");
}

//菜单界面
void showMenu()
{	
	cout << "**********************" << endl;
	cout << "**** 1.添加联系人 ****" << endl;
	cout << "**** 2.显示联系人 ****" << endl;
	cout << "**** 3.删除联系人 ****" << endl;
	cout << "**** 4.查找联系人 ****" << endl;
	cout << "**** 5.修改联系人 ****" << endl;
	cout << "**** 6.清空联系人 ****" << endl;
	cout << "**** 0.退出通讯录 ****" << endl;
	cout << "**********************" << endl;
}

int main()
{	
	//创建结构体变量
	Addressbooks abs;
	//初始化通讯录当前人员个数
	abs.m_Size = 0;
	
	int select = 0;

	while (true)
	{
		showMenu();
		cin >> select;

		switch (select)
		{
		case 1:  //1.添加联系人
			addPerson(&abs);//利用地址传递，可以修改实参
			break;
		case 2: //2.显示联系人
			showPerson(&abs);
			break;
		case 3: //3.删除联系人
		{
			deletePerson(&abs);
			break;
		}
		case 4: //4.查找联系人
			findPerson(&abs);
			break;
		case 5: //5.修改联系人
			modifyPerson(&abs);
			break;
		case 6: //6.清空联系人
		{	
			cout << "是否真的要清空所有联系人" << endl;
			cout << "1 ---- 确认" << endl;
			cout << "2 ---- 取消" << endl;
			int rrr = 0;
			cin >> rrr;
			if (rrr == 1) 
			{
				cleanPerson(&abs);
			}
			else
			{
				cout << "取消操作" << endl;
				system("pause");
				system("cls");
			}
			break;
		}
		case 0: //0.退出通讯录
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