/*
 Calculate Overload Add
 加法运算符重载
 实现两个自定义数据类型相加的运算
*/

#include <iostream>
using namespace std;

class Person
{
private:
    /* data */
public:
    Person(){};
    Person(int a, int b);
    Person operator+(const Person &p)
    {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }
    ~Person();
    int m_A;
    int m_B;
};

Person::Person(int a, int b)
{
    cout << "Person 有参构造函数！" << endl;
    this->m_A = a;
    this->m_B = b;
}


Person::~Person()
{
    cout << "Person 析构函数！" << endl;
}



// 全局函数实现 + 号运算符重载
Person operator+(const Person &p1, const Person &p2)
{
    Person temp(0, 0);
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}

// 运算符重载，可以发生函数重载
Person operator+(const Person &p2, int val)
{
    Person temp;
    temp.m_A = p2.m_A + val;
    temp.m_B = p2.m_B + val;
    return temp;

}

void test()
{
    Person p1(10, 10);
    Person p2(20, 20);

    // 全局函数 和局部函数均可以用下面方式
    // 相当于 p1.operator+(p1)
    Person p3 = p1 + p2; 
    cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;

    Person p4 = p3 + 10;  // 相当于 operator+(p3,10)
    cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;

}

int main()
{
    test();
    system("pause");
    return 0;
}