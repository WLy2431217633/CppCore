/*
深浅拷贝是面试经典问题，也是常见的一个坑

浅拷贝：简单的**赋值拷贝**操作

深拷贝：在**堆区重新申请空间**，进行**拷贝**操作
*/
#include<iostream>
using namespace std;

class Person
{
private:
    /* data */
public:
    Person(/* args */);
    Person(int age, int height);
    Person(const Person& person);
    ~Person();
    int m_Age;
    int* m_Height;
};

Person::Person(/* args */)
{
    cout << "无参构造函数!" << endl;
}

Person::Person(int age, int height)
{
    cout << "有参构造函数!" << endl;
    m_Age = age;
    // 堆区开辟
    m_Height = new int(height);
    
}

// 拷贝构造函数
Person::Person(const Person& person)
{
    cout << "拷贝构造函数！" << endl;
    //如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
    m_Age = person.m_Age;
    m_Height = new int (*person.m_Height);

}

Person::~Person()
{
    cout << "析构函数！" << endl;
    if(m_Height != NULL)
        delete m_Height;
}

void test01()
{
    // 创建对象
    Person person1(18, 170);
    // 拷贝构造
    Person person2(person1);

    cout << "person1的年龄:" << person1.m_Age << "身高：" << *person1.m_Height << endl;
    
    cout << "person2的年龄:" << person2.m_Age << "身高：" << *person2.m_Height << endl;
    /*
    有参构造函数!
    拷贝构造函数！
    person1的年龄:18身高：170
    person2的年龄:18身高：170
    析构函数！
    析构函数！
    */
}

int main()
{
    test01();
    //总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
    system("pause");
    return 0;
}

