#include <iostream>

/*
* C++中在程序运行前分为全局区和代码区
* 代码区特点是共享和只读
* 全局区中存放全局变量、静态变量、常量
* 常量区中存放 const修饰的全局常量  和 字符串常量
* 局部变量、常量放 栈区
*/
using namespace std;

int * func()
{
    int p = 10;
    return &p;
}

int *func1()
{
    int *p = new int(10);
    return p;
}

// 全局变量
int global_a = 10;
int global_b = 10;

// 全局常量
const int const_global_a = 10;
const int const_global_b = 10;

int main()
{
    // 局部变量
    int local_a = 10, local_b = 10;

    // 打印地址
    cout << "局部变量 a 的地址：" << &local_a << endl;
    cout << "局部变量 b 的地址：" << &local_b << endl;

    cout << "全局变量 global_a 的地址：" <<  &global_a << endl;
    cout << "全局变量 global_b 的地址：" <<  &global_b << endl;

    // 静态变量
    static int static_a = 10;
    static int static_b = 10;

    cout << "静态变量 static_a 的地址：" <<  &static_a << endl;
    cout << "静态变量 static_b 的地址：" <<  &static_b << endl;

    cout << "字符串常量地址为：" << &"hello world" << endl;
    cout << "字符串常量地址为：" << &"hello world1" << endl;

    cout << "全局常量const_global_a的地址为:" << &const_global_a << endl;
    cout << "全局常量const_global_b的地址为:" << &const_global_b << endl;
    
    // 局部常量
    const int const_local_a = 10;
    const int const_local_b = 10;
    
    cout << "局部常量const_local_a的地址为:" << &const_local_a << endl;
    cout << "局部常量const_local_b的地址为:" << &const_local_b << endl;


    // 栈区
    int *p1 = func();
    cout << "栈区地址：" << &p1 << endl;

    delete p1;
    cout << "栈区地址:" << &p1 << endl;


    // 堆区使用new开辟内存，由编译器释放
    int *p2 = func1();
    cout << "堆区地址：" << &p2 << endl;
    /*堆区的数据由程序员管理开辟，释放；如果想释放堆区的数据用关键字delete*/
    delete p2;
    cout << "堆区地址：" << &p2 << endl;

    // 开辟数组
    int *arr = new int[10];
    for (int i = 0; i < 10; i++)
        arr[i] = i+100;
    for (int i = 0; i < 10; i++)
        cout << arr[i] << endl;
    // 释放数组 delete 后加[]
    delete[] arr;
    

    

    /*
    局部变量 a 的地址：0x4c6cdff81c
    局部变量 b 的地址：0x4c6cdff818
    全局变量 global_a 的地址：0x7ff6fda19010
    全局变量 global_b 的地址：0x7ff6fda19014
    静态变量 static_a 的地址：0x7ff6fda19018
    静态变量 static_b 的地址：0x7ff6fda1901c
    字符串常量地址为：0x7ff6fda1c0b3
    字符串常量地址为：0x7ff6fda1c0bf
    全局常量const_global_a的地址为:0x7ff6fda1c004
    全局常量const_global_b的地址为:0x7ff6fda1c008
    局部常量const_local_a的地址为:0x4c6cdff814
    局部常量const_local_b的地址为:0x4c6cdff810
    栈区地址：0x4c6cdff808
    栈区地址:0x4c6cdff808
    堆区地址：0x4c6cdff800
    堆区地址：0x4c6cdff800
    100
    101
    102
    103
    104
    105
    106
    107
    108
    109
    */


    system("pause");

    return 0;
}

