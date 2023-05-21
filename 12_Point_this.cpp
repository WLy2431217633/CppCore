// this 指针
/*
c++通过提供特殊的对象指针，this指针，解决上述问题。
**this指针指向被调用的成员函数所属的对象**


this指针是隐含每一个非静态成员函数内的一种指针
this指针不需要定义，直接使用即可


this指针的用途：

*  当形参和成员变量同名时，可用this指针来区分
*  在类的非静态成员函数中返回对象本身，可使用return *this
*/

#include <iostream>
using namespace std;

class Person
{
private:
    /* data */
public:
    Person(int age);
    ~Person();
    Person& PersonAddPerson(Person person);
    int age;

    // 空指针访问成员函数
    void ShowClassName();
    void ShowPerson();
    int m_Age;
};

Person::Person(int age)
{
    // 1、当形参和成员变量同名时，可用this指针来区分
    this->age = age;
    cout << "构造函数调用" << endl;
}

Person::~Person()
{
    cout << "析构函数调用！" << endl;
}

// 返回值用引用类型
Person& Person::PersonAddPerson(Person person)
{
    this->age += person.age;
    return *this;
}

void test01()
{
    Person person1(10);
    cout << "person1.age = " << person1.age << endl;

    Person person2(10);
    person2.PersonAddPerson(person1).PersonAddPerson(person1).PersonAddPerson(person1);
    cout << "person2.age = " << person2.age << endl;

    /*
    构造函数调用
    person1.age = 10
    构造函数调用
    析构函数调用！
    析构函数调用！
    析构函数调用！
    person2.age = 40
    析构函数调用！
    析构函数调用！
    */
}

/*
#### 空指针访问成员函数

C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针

如果用到this指针，需要加以判断保证代码的健壮性
*/


void Person::ShowClassName()
{
    cout << "Person类!" << endl;
}

void Person::ShowPerson()
{
    if(this == NULL)
        return; // 空指针直接返回
    cout << m_Age << endl;
}

void test02()
{
    Person *person = NULL;
    person->ShowClassName(); // 空指针可以调用成员函数
    person->ShowPerson();   // 但如果成员函数中用了this指针，就不可以了
    // Person类!
}



int main()
{
    test01();
    test02();
    
    system("pause");
    return 0;
}