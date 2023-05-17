//类对象和类成员
/*
C++类中的成员可以是另一个类的对象，我们称该成员为 对象成员
B类中有对象A作为成员，A为对象成员

那么当创建B对象时，A与B的构造和析构的顺序是谁先谁后？
//当类中成员是其他类对象时，我们称该成员为 对象成员
//构造的顺序是 ：先调用对象成员的构造，再调用本类构造
//析构顺序与构造相反

*/
#include <iostream>

using namespace std;

class Phone
{
private:
    /* data */
public:
    Phone(string name);
    ~Phone();
    string m_PhoneName;
};

Phone::Phone(string name)
{
    m_PhoneName = name;
    cout << "Phone构造" << endl;
}

Phone::~Phone()
{
    cout << "Phone析构" << endl;
}

class Person
{
private:
    /* data */
public:
    Person(string name, string pName);
    ~Person();
    void playGame();
    string m_Name;
    Phone m_Phone;
};

Person::Person(string name, string pName):m_Name(name), m_Phone(pName)
{
    cout << "Person 构造" << endl;
}

Person::~Person()
{
    cout << "Person 析构" << endl;
}

void Person::playGame()
{
    cout << m_Name << "使用" << m_Phone.m_PhoneName << "手机！" << endl; 
}

void test01()
{
    Person person("张三", "iphone 14 pro max");
    person.playGame();
}

int main()
{
    test01();
    /*
    Phone构造
    Person 构造
    张三使用iphone 14 pro max手机！
    Person 析构
    Phone析构
    */
    system("pause");
    return 0;
}
