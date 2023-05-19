#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Animal
{

public:
	Animal()
	{
		cout << "Animal 构造函数的调用" << endl;
	}

	//利用虚析构可以解决 父类指针释放子类对象时不干净的问题
	/*virtual ~Animal()
	{
		cout << "Animal 虚析构函数的调用" << endl;
	}*/
	//纯虚析构  需要声明 也需要实现
	//有了纯虚析构函数之后，这个类也属于抽象类，无法实例化对象
	virtual ~Animal() = 0;


	virtual void speak() = 0;
};

Animal::~Animal()
{
	cout << "Animal 纯虚析构函数的调用" << endl;
}

class Cat : public Animal
{	
public:

	Cat(string name)
	{
		cout << "Cat 构造函数的调用" << endl;
		m_Name = new string(name);
	}


	 void speak()
	{
		cout << *m_Name << "小猫在说话" << endl;
	}
	 
	 ~Cat()
	 {
		 cout << "Cat 析构函数的调用" << endl;
		 if (m_Name != NULL)
		 {
			 delete m_Name;
			 m_Name = NULL;
		 }
	 }

	 string *m_Name;
};

void test01()
{
		Animal* animal = new Cat("Tom");
		animal->speak();
		delete animal;
}

int main()
{	
	test01();
	system("pause");
	return 0;
}
