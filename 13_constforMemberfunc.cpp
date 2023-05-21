/*
#### const修饰成员函数

**常函数：**

* 成员函数后加const后我们称为这个函数为**常函数**
* 常函数内不可以修改成员属性
* 成员属性声明时加关键字mutable后，在常函数中依然可以修改

**常对象：**

* 声明对象前加const称该对象为常对象
* 常对象只能调用常函数
*/

#include <iostream>
using namespace std;

class Person
{
private:
    /* data */
public:
    Person(/* args */);
    ~Person();
    void ShowPerson() const;
    void MyFunc() const;

    int m_A;
    // 可修改的
    mutable int m_B;
};

Person::Person(/* args */)
{
    m_A = 0;
    m_B = 0;
    cout << "构造函数！" << endl;
}

Person::~Person()
{
    cout << "析构函数！" << endl;
}

void Person::ShowPerson() const 
{
    //const Type* const pointer;
	// this = NULL; //不能修改指针的指向 Person* const this;
	// this->mA = 100; //但是this指针指向的对象的数据是可以修改的

    //const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
    this->m_B = 100;

    cout << "ShowPerson() const 调用" << endl;
}

void Person::MyFunc() const
{
    // m_A = 10000;
    cout << "MyFunc() const 调用" << endl;
}

//const修饰对象  常对象
void test01() 
{
    const Person person; // 常量对象
    cout << "person.m_A:" << person.m_A << endl;

    //常对象不能修改成员变量的值,但是可以访问
    // person.m_A = 100; 

    //但是常对象可以修改mutable修饰成员变量
    person.m_B = 100;
    cout << "person.m_B:" << person.m_B << endl;

    //常对象访问成员函数
    person.MyFunc();  //常对象不能调用const的函数
    person.ShowPerson(); 

    /*
    构造函数！
    person.m_A:0
    person.m_B:100
    MyFunc() const 调用
    ShowPerson() const 调用
    析构函数！
    */
}


int main()
{
    test01();

    system("pause");
    return 0;
}