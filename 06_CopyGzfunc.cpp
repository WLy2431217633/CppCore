/*
C++中拷贝构造函数调用时机通常有三种情况

* 使用一个已经创建完毕的对象来初始化一个新对象
* 值传递的方式给函数参数传值
* 以值方式返回局部对象
*/
#include <iostream>
using namespace std;

class Person
{
private:
    /* data */
public:
    // 无参构造
    Person(/* args */);
    // 有参构造
    Person(int age);
    // 拷贝构造
    Person(const Person& person);
    // 析构函数   在释放内存之前调用
    ~Person();
    int mAge;
};

// 无参构造
Person::Person(/* args */)
{
    cout << "无参构造函数调用！" << endl;
    mAge = 0;
}

// 有参构造
Person::Person(int age)
{
    cout << "有参构造函数调用！" << endl;
    mAge = age;
}

// 拷贝构造
Person::Person(const Person& person)
{
    cout << "拷贝构造函数调用！" << endl;
    mAge = person.mAge;
}

// 析构函数
Person::~Person()
{
    cout << "析构函数调用" << endl;
}

// 1. 使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
    Person man(10); // person 对象已经创建完毕
    Person newman(man); // 调用拷贝构造函数
    Person newman2 = man;  // 拷贝构造

    Person newman3;
    newman3 = man;  // 不是调用拷贝函数，而是赋值操作
}

// 2.值传递的方式给函数参数传值
// 相当于 Person p1 = p;
void doWork(Person Person1){}
void test02()
{
    Person person;  // 无参构造
    doWork(person);
}

// 3.以值方式返回局部对象
Person doWork2()
{
    Person person1;
    cout << (int *)&person1 << endl;
    return person1;
}

void test03()
{
    Person person = doWork2();
    cout << (int*)&person << endl;
}



/*
默认情况下，c++编译器至少给一个类添加3个函数

1．默认构造函数(无参，函数体为空)

2．默认析构函数(无参，函数体为空)

3．默认拷贝构造函数，对属性进行值拷贝



构造函数调用规则如下：

* 如果用户定义有参构造函数，c++不在提供默认无参构造，但是会提供默认拷贝构造


* 如果用户定义拷贝构造函数，c++不会再提供其他构造函数
*/

void test04()
{
    Person person1(18);
    //如果不写拷贝构造，编译器会自动添加拷贝构造，并且做浅拷贝操作
    Person person2(person1);
    cout << "person2 的年龄为：" << person2.mAge << endl;
}

void test05()
{
    //如果用户提供有参构造，编译器不会提供默认构造，会提供拷贝构造
    Person person1; // 此时如果用户自己不提供默认构造，则会出错
    Person person2(10); // 用户提供有参
    Person person3(person2); // 此时如果用户没有提供拷贝构造，编译器会自动提供

    //如果用户提供拷贝构造，编译器不会提供其他构造函数
	Person person4; //此时如果用户自己没有提供默认构造，会出错
	Person person5(10); //此时如果用户自己没有提供有参，会出错
	Person person6(person5); //用户自己提供拷贝构造
}


int main()
{
    test01();
    /*
    有参构造函数调用！
    拷贝构造函数调用！
    拷贝构造函数调用！
    无参构造函数调用！
    析构函数调用
    析构函数调用
    析构函数调用
    析构函数调用
    */

    test02();
    /*
    无参构造函数调用！
    拷贝构造函数调用！
    析构函数调用
    析构函数调用
    */

    test03();
    /*
    无参构造函数调用！
    0xcc191ff92c
    0xcc191ff92c
    析构函数调用
    */
    test04();
    /*
    有参构造函数调用！
    拷贝构造函数调用！
    person2 的年龄为：18
    析构函数调用
    析构函数调用
    */

    test05();
    /*
    无参构造函数调用！
    有参构造函数调用！
    拷贝构造函数调用！
    无参构造函数调用！
    有参构造函数调用！
    拷贝构造函数调用！
    析构函数调用
    析构函数调用
    析构函数调用
    析构函数调用
    析构函数调用
    析构函数调用
    */

    system("pause");
    return 0;
}