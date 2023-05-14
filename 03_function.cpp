// 函数
#include <iostream>

using namespace std;

// 1、函数默认参数
// 函数的形参列表中的形参是可以有默认值的
int func1(int a, int b = 10, int c = 10)
{
    return a + b + c;
}
//1.1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
int func2(int a = 10, int b = 10);
//1.2. 如果函数声明有默认值，函数实现的时候就不能有默认参数
int func2(int a, int b)
{
    return a + b;
}

// 2 函数占位参数
// C++中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置
void func3(int a, int)
{
    cout << "this is func3" << endl;
}


// 3 函数重载
/*
**函数重载满足条件：**

* 同一个作用域下
* 函数名称相同
* 函数参数**类型不同**  或者 **个数不同** 或者 **顺序不同**
*/

void func4()
{
	cout << "func4 的调用！" << endl;
}
void func4(int a)
{
	cout << "func4 (int a) 的调用！" << endl;
}
void func4(double a)
{
	cout << "func4 (double a)的调用！" << endl;
}
void func4(int a ,double b)
{
	cout << "func4 (int a ,double b) 的调用！" << endl;
}
void func4(double a ,int b)
{
	cout << "func4 (double a ,int b)的调用！" << endl;
}

//函数返回值不可以作为函数重载条件
//int func4(double a, int b)
//{
//	cout << "func (double a ,int b)的调用！" << endl;
//}

// #### 3.2 函数重载注意事项
// * 引用作为重载条件
void func5(int &a)
{
	cout << "func5 (int &a) 调用 " << endl;
}

void func5(const int &a)
{
	cout << "func5 (const int &a) 调用 " << endl;
}
// * 函数重载碰到函数默认参数
void func6(int a, int b = 10)
{
	cout << "func6(int a, int b = 10) 调用" << endl;
}

void func6(int a)
{
	cout << "func6(int a) 调用" << endl;
}


int main()
{

    //1、函数默认参数
    cout << "ret = " << func1(20, 20) << endl;  // 20 + 20 + 10 = 50
	cout << "ret = " << func1(100) << endl;     // 100 + 10 + 10 = 120
    cout << "ret = " << func2(100) << endl;     // 100 + 10 + 0 = 110
    
    // 2 函数占位参数
    // 占位参数必须填补
    func3(10, 10);

    // 3 函数重载
	func4();
	func4(10);
	func4(3.14);
	func4(10,3.14);
	func4(3.14 , 10);

    // #### 3.2 函数重载注意事项
    // * 引用作为重载条件
    int a = 10;
	func5(a); //调用无const
	func5(10);//调用有const
    // * 函数重载碰到函数默认参数
    // func6(10); //碰到默认参数产生歧义，需要避免


    system("pause");    

	return 0;

}