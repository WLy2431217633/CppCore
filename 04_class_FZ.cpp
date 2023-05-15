// 4.1封装
// 封装是C++面向对象三大特性之一

// 封装的意义：

// * 将属性和行为作为一个整体，表现生活中的事物
// * 将属性和行为加以权限控制

// **封装意义一：**

// ​	在设计类的时候，属性和行为写在一起，表现事物
// 设计一个圆类，求圆的周长
#include <iostream>

using namespace std;

const double PI = 3.14;

//1、封装的意义
//将属性和行为作为一个整体，用来表现生活中的事物

//封装一个圆类，求圆的周长
//class代表设计一个类，后面跟着的是类名
class Circle
{
public:
    int m_r;  // 半径
    double calculatorZC()
    {
        return 2 * PI * m_r;
    }
};

// 设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
class student
{
public:
    void setName(string name)
    {
        m_name = name;
    }
    void setID(int id)
    {
        m_id = id;
    }
    void showStudent()
    {
        cout << "name is " <<m_name << "ID is " << m_id << endl;
    }
    
public:
    string m_name;
    int m_id;
};


/*
**封装意义二：**

类在设计时，可以把属性和行为放在不同的权限下，加以控制

访问权限有三种：

//公共权限  public     类内可以访问  类外可以访问
//保护权限  protected  类内可以访问  类外不可以访问
//私有权限  private    类内可以访问  类外不可以访问
*/

class Person
{
public:
    // 姓名 公有权限
    string m_Name;

protected:
    // 汽车 保护权限
    string m_Car;

private:
    // 银行卡密码 私有权限
    int m_Password;

public:
    void func()
    {
        m_Name = "张三";
        m_Car = "保时捷";
        m_Password = 666666;
    }
};



int main()
{
    //通过圆类，创建圆的对象
	// c1就是一个具体的圆
    Circle c1;
    c1.m_r = 10;
    cout << "圆的周长为：" << c1.calculatorZC() << endl;   // 62.8

    // 学生类
    student stu;
    stu.setName("Harry");
    stu.setID(190);
    stu.showStudent();

    // 人
    Person person;
    person.m_Name = "李四";
	//person.m_Car = "奔驰";  //保护权限类外访问不到
	//person.m_Password = 123; //私有权限类外访问不到
    cout << person.m_Name << endl;

    system("pause");

    return 0;
}