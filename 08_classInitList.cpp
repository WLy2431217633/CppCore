/*
#### 初始化列表
**作用：**
C++提供了初始化列表语法，用来初始化属性
**语法：**`构造函数()：属性1(值1),属性2（值2）... {}`
*/
#include <iostream>

using namespace std;

// 传统方式初始化
class Person1
{
public:
    Person1(int a, int b, int c);
    ~Person1();
private:
    int m_A;
    int m_B;
    int m_C;

};

Person1::Person1(int a, int b, int c)
{
    m_A = a;
    m_B = b;
    m_C = c;
}

Person1::~Person1(){}

// 初始化列表方式初始化
class Person2
{
private:
    int m_A;
    int m_B;
    int m_C;
public:
    Person2(int a, int b, int c);
    ~Person2();
    void PrintPerson();
};

Person2::Person2(int a, int b, int c) : m_A(a), m_B(b), m_C(c){}
Person2::~Person2(){}
void Person2::PrintPerson() 
{
    cout << "mA: " << m_A << endl;
    cout << "mB: " << m_B << endl;
    cout << "mC: " << m_C << endl;
}

int main()
{
    Person1 person1(1, 2, 3);
    
    Person2 person2(1, 2, 3);
    person2.PrintPerson();
    /*
    mA: 1
    mB: 2
    mC: 3
    */
    system("pause");
    return 0;
}
