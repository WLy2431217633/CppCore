/*
静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员
静态成员分为：
*  静态成员变量
   *  所有对象共享同一份数据
   *  在编译阶段分配内存
   *  类内声明，类外初始化
*  静态成员函数
   *  所有对象共享同一个函数
   *  静态成员函数只能访问静态成员变量
*/
#include <iostream>

using namespace std;

class Person
{
// 静态成员变量
private:
    static int m_B; //静态成员变量也是有访问权限的
    // 私有静态成员函数
    static void func2();

public:
    Person(/* args */);
    ~Person();
    static int m_A; // 静态成员变量
    int m_C;
    //静态成员变量特点：
	//1 在编译阶段分配内存
	//2 类内声明，类外初始化
	//3 所有对象共享同一份数据

    //静态成员函数特点：
	//1 程序共享一个函数
	//2 静态成员函数只能访问静态成员变量
    static void func1();
};

// 全局变量
int Person::m_A = 10;
int Person::m_B = 10;

Person::Person(/* args */)
{
    cout << "无参构造！" << endl;
}

Person::~Person()
{
    cout << "析构函数！" << endl;
}


void test01()
{
    // 静态成员变量两种访问方式
    // 1、通过对象
    Person person1;
    cout << "m_A = " << Person::m_A << endl;
    person1.m_A = 100;
    cout << "person1.m_A = " << person1.m_A << endl;

    Person person2;
    person2.m_A = 200;
    // 共享同一份数据
    cout << "person1.m_A = " << person1.m_A << endl;  // 200
    cout << "person2.m_A = " << person2.m_A << endl;  // 200

    // 2、通过类名
    cout << "m_A = " << Person::m_A << endl;

    // 私有权限无法访问
    // cout << "m_B = " << Person::m_B << endl;

    /*
    无参构造！
    m_A = 10
    person1.m_A = 100
    无参构造！
    person1.m_A = 200
    person2.m_A = 200
    m_A = 200
    析构函数！
    析构函数！
    */

}

void Person::func1()
{
    cout << "func1调用!" << endl;
    m_A = 100;
    // m_C = 100; // 不可以访问非静态成员变量
}

void Person::func2()
{
    cout << "func2调用!" << endl;
}

void test02()
{
    // 静态成员变量两种访问方式
    // 1、通过对象
    Person person1;
    person1.func1();

    // 2、通过类名
    Person::func1();

    // Person::func2(); 私有权限访问不到


    /*
    无参构造！
    func1调用!
    func1调用!
    析构函数！

    */
}

int main()
{
    test01();
     cout << endl;
    test02();
    system("pause");
    return 0;
}