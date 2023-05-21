#include"workManager.h"

workManager::workManager()
{
	ifstream ofs;
	ofs.open(FILENAME, ios::in);

	//1.文件不存在
	if (!ofs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->m_EmpNum = 0;//初始化人数
		this->m_EmpArry = NULL;//初始化数组指针
		this->m_FileIsEmpty = true;//初始文件为空标志
		ofs.close();
		return;
	}

	//2.文件存在，但数据为空
	char ch;
	ofs >> ch;
	if (ofs.eof())
	{
		//cout << "文件为空" << endl;
		this->m_EmpNum = 0;//初始化人数
		this->m_EmpArry = NULL;//初始化数组指针
		this->m_FileIsEmpty = true;//初始文件为空标志
		ofs.close();
		return;
	}

	//3.文件存在，并且记录了数据
	this->m_EmpNum = this->get_EmpNum();
	//cout << "职工的人数为：" << this->m_EmpNum << endl;

	this->m_EmpArry = new Worker * [this->m_EmpNum];
	this->init_Emp();


}

void workManager::showMenu()
{
	cout << "**********************************" << endl;
	cout << "****** 欢迎使用职工管理系统 ******" << endl;
	cout << "******    0.退出管理程序    ******" << endl;
	cout << "******    1.增加职工信息    ******" << endl;
	cout << "******    2.显示职工信息    ******" << endl;
	cout << "******    3.删除职工信息    ******" << endl;
	cout << "******    4.修改职工信息    ******" << endl;
	cout << "******    5.查找职工信息    ******" << endl;
	cout << "******    6.按照编号排序    ******" << endl;
	cout << "******    7.清空所有文档    ******" << endl;
	cout << "**********************************" << endl;
	cout << endl;
}

void workManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void workManager::Add_Emp()
{
	cout << "请输入需要添加的职工个数:" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//添加
		//计算新开辟空间大小
		int newSize = this->m_EmpNum + addNum;
		//开辟新空间
		Worker** newSpace = new Worker* [newSize];

		//将原来的数据添加到新空间
		if (this->m_EmpArry != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArry[i];
			}
		}
		
		//添加新员工
		for (int i = 0; i < addNum; i++)
		{
			int id = 0;
			string name;
			int dSelect;

			cout << "请输入第" << i + 1 << "个员工编号" << endl;
			while (true)
			{	
				cin >> id;
				int j = 0;
				for ( j; j < this->m_EmpNum; j++)
				{
					if (this->m_EmpArry[j]->m_Id == id)
					{
						cout << "输入职工编号重复，请重新输入" << endl;
						break;
					}
				}
				if (j == this->m_EmpNum)
				{
					break;
				}
			}
			cout << "请输入第" << i + 1 << "个员工姓名" << endl;
			cin >> name;

			cout << "请选择第" << i + 1 << "个员工职位" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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

			//将员工保存到数组
			newSpace[this->m_EmpNum + i] = worker;

		}
		//清空原有数据
		delete[] this->m_EmpArry;

		//更新员工数据
		this->m_EmpArry = newSpace;

		//更新员工数量
		this->m_EmpNum = newSize;

		//更改文件标志 为 不为空
		this->m_FileIsEmpty = false;

		cout << "成功添加" << addNum << "名职工" << endl;

		this->save();
	}
	else
	{
		cout << "输入错误" << endl;
	}

	system("pause");
	system("cls");
}

void workManager::save()
{
	ofstream ofs;

	ofs.open(FILENAME, ios::out);

	//写文件
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArry[i]->m_Id << " "
			<< this->m_EmpArry[i]->m_Name << " "
			<< this->m_EmpArry[i]->m_Did << " "
			<< endl;
	}
	//关闭文件
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
		cout << "文件不存在或记录为空" << endl;
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

//删除职工
void workManager::Del_Emp()
{	
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空 " << endl;
	}
	else
	{
		int id;
		cout << "请输入要删除员工编号: " << endl;
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
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "该职工不存在" << endl;
		}
	}
	system("pause");
	system("cls");
}


//判度职工是否存在
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
		cout << " 文件不存在或数据为空 " << endl;
	}
	else
	{
		int id;
		string name;
		int dSelect;

		cout << "请输入要修改的职工编号" << endl;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1)
		{	
			delete this->m_EmpArry[index];

			cout << "请输入新的员工编号" << endl;
			while (true)
			{
				cin >> id;
				int j = 0;
				for (j; j < this->m_EmpNum; j++)
				{
					if (this->m_EmpArry[j]->m_Id == id)
					{
						cout << "输入职工编号重复，请重新输入" << endl;
						break;
					}
				}
				if (j == this->m_EmpNum)
				{
					break;
				}
			}
			cout << "请输入新的职工姓名" << endl;
			cin >> name;
			cout << "请选择新的职工职位" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
			//更新信息
			this->m_EmpArry[index] = worker;
			//将数据保存到文件中
			this->save();
		}
		else
		{
			cout << "该职工不存在" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workManager::Fin_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或数据为空" << endl;
	}
	else
	{
		cout << "请选择查找方式: " << endl;
		cout << "1.按职工编号进行查找" << endl;
		cout << "2.按职工姓名进行查找" << endl;
		int select;
		cin >> select;

		switch (select)
		{
		case 1:
		{
			cout << "请输入要查找职工编号" << endl;
			int id;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功，该职工信息如下：" << endl;
				this->m_EmpArry[ret]->showInfo();
			}
			else
			{
				cout << "查无此人" << endl;
			}
			break;
		}
		case 2:
		{
			cout << "请输入要查找职工姓名" << endl;
			string name;

			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArry[i]->m_Name == name)
				{
					cout << "查找成功,编号为" << this->m_EmpArry[i]->m_Id << "职工信息如下" << endl;
					this->m_EmpArry[i]->showInfo();
					flag = true;
				}
			}
			if (flag)
			{
				cout << "查无此人" << endl;
			}
		}
		default:
			cout << "输入有误" << endl;
			break;
		}

	}
}

void workManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或数据为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1.按升序方式排序" << endl;
		cout << "2,按降序方式排序" << endl;
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
		cout << "排序成功,排序结果为" << endl;
		this->save();
		this->Show_Emp();
	}
}

void workManager::Clean_File()
{
	cout << "是否确认清空文件" << endl;
	cout << "1,确认" << endl;
	cout << "2.取消" << endl;
	int Select;
	cin >> Select;

	if (Select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//清空文件再重新创建文件
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