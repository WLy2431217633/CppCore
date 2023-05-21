//  成员变量和成员函数分开存储

// 在C++中，类内的成员变量和成员函数分开存储

// 只有非静态成员变量才属于类的对象上
#include <iostream>
using namespace std;


class Person
{
private:
    /* data */
public:
    Person(/* args */);
    ~Person();
    
    // 非静态成员变量占对象空间
    int m_A;
    // 静态成员变量不占对象空间
    static int m_B;
    // 函数也不占对象空间，所有函数共享一个函数示例
    void func();
    // 静态成员函数也不占对象空间
    static void sfunc();

};

Person::Person(/* args */)
{
    m_A = 0;
    cout << "无参构造！" << endl;
}

Person::~Person()
{
    cout << "有参构造！" << endl;
}

void Person::func()
{
    cout << "m_A:" << this->m_A << endl;
}

void Person::sfunc()
{

}

int main()
{
    cout << sizeof(Person) << endl;
    system("pause");
    return 0;
}