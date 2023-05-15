// 类和结构体
/*
在C++中 struct和class唯一的**区别**就在于 **默认的访问权限不同**

区别：

* struct 默认权限为公共
* class   默认权限为私有
*/

#include <iostream>

using namespace std;

class C1
{
    int m_A = 10; // 类中默认私有权限
};

struct C2
{
    int m_A = 10; // 结构体默认公有 
};

/*
#### 成员属性设置为私有

**优点1：**将所有成员属性设置为私有，可以自己控制读写权限

**优点2：**对于写权限，我们可以检测数据的有效性
*/
class Person
{
public:
    // 姓名设置 可读可写
    void setName(string name)
    {
        m_Name = name;
    }    
    string getName()
    {
        return m_Name;
    }

    // 获取年龄
    int getAge()
    {
        return m_Age;
    }
    // 设置年龄
    void setAge(int age)
    {
        if(age < 0 || age > 150)
        {
            cout << "年龄错误！" << endl;
            return;
        }
        m_Age = age;
    }

    // 情人只写
    void setLover(string lover)
    {
        m_Lover = lover;
    }


private:
    string m_Name;   // 姓名 可读可写
    int m_Age;       // 年龄  只读
    string m_Lover;  // 情人  只写
};



int main()
{

    C1 c1;
    // c1.m_A = 10; //错误，访问权限是私有
    // cout << c1.m_A << endl;
    C2 c2;
    c2.m_A = 20; //正确，访问权限是公共
    cout << c2.m_A << endl;

    Person person;
    person.setName("张三");
    person.setAge(18);
    person.setLover("angie");

    cout << "姓名：" << person.getName() << endl;
    cout << "年龄：" << person.getAge() << endl;
    // cout << "情人：" << person.m_Lover << endl;

    system("pause");
    return 0;
}
