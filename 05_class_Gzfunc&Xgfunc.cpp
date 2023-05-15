// 构造函数和析构函数
/*
* 构造函数：主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无须手动调用。
* 析构函数：主要作用在于对象**销毁前**系统自动调用，执行一些清理工作。
*/

/*
#### 构造函数的分类及调用

两种分类方式：

​	按参数分为： 有参构造和无参构造

​	按类型分为： 普通构造和拷贝构造

三种调用方式：

​	括号法

​	显示法

​	隐式转换法


*/
#include <iostream>
using namespace std;

class Person
{
private:
    /* data */
public:
    Person(/* args */);
    Person(int a);
    Person(const Person& person);
    ~Person();
    int age;
};

// 无参构造函数
Person::Person(/* args */)
{
    cout << "Person 的无参构造函数调用" << endl;
}

// 有参构造
Person::Person(int a)
{
    age = a;
    cout << "Person 的有参构造函数调用" << endl;
}

// 拷贝构造函数
Person::Person(const Person& person)
{
    age = person.age;
    cout << "拷贝构造函数！" << endl;
}


// 析构函数
Person::~Person()
{
    cout << "Person 的析构函数调用" << endl;
}



//2、构造函数的调用
//调用无参构造函数
void test01()
{
    Person person;  //调用无参构造函数
}

// 调用有参的构造函数
void test02()
{
    //2.1  括号法，常用
    Person person1(10);
    //注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
    // Person person2();

    //2.2 显式法
    Person person2 = Person(10);
    Person person3 = Person(person2);
    //Person(10)单独写就是匿名对象  当前行结束之后，马上析构

    //2.3 隐式转换法
    Person person4 = 10;  // Person person4 = Person(10);
    Person person5 = person4; // Person person5 = Person(person4);

    //注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明
    // Person person5(person4);

    // 可以如此
    Person person6(person5);//调用拷贝构造函数
}

int main()
{
    test01();
    /*
    Person 的无参构造函数调用
    Person 的析构函数调用   
    */
   
    test02();
    /*
    Person 的有参构造函数调用
    Person 的有参构造函数调用
    拷贝构造函数！
    Person 的有参构造函数调用
    拷贝构造函数！
    拷贝构造函数！
    Person 的析构函数调用
    Person 的析构函数调用
    Person 的析构函数调用
    Person 的析构函数调用
    Person 的析构函数调用
    Person 的析构函数调用
    */

    system("pause");
    return 0;
}