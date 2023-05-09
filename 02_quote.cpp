// 引用
#include <iostream>

using namespace std;

// 函数传参
//1. 值传递
void mySwap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

//2. 地址传递
void mySwap02(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//3. 引用传递
void mySwap03(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

// 函数返回值
// 返回局部变量引用
int& test01()
{
    int a = 10; // 局部变量
    return a;
}

// 返回静态变量引用
int& test02()
{
    static int a = 20; // 静态变量
    return a;
}

//发现是引用，转换为 int* const ref = &a;
void func(int& ref){
	ref = 100; // ref是引用，转换为*ref = 100
}

//引用使用的场景，通常用来修饰形参
void showValue(const int& v) {
	//v += 10; // const不可修改
	cout << v << endl;
}

int main()
{

    // 1起别名 语法： 数据类型 &别名 = 原名
    int a = 10;
    int &b = a;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    b = 100;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    /*
    a = 10
    b = 10
    a = 100
    b = 100
    */


    // 2引用必须初始化
    int a1 = 10;
	int b1 = 20;
	//int &c1; //错误，引用必须初始化
	int &c1 = a1; //一旦初始化后，就不可以更改
	c1 = b1; //这是赋值操作，不是更改引用
    cout << "a1 = " << a1 << endl; // 20
	cout << "b1 = " << b1 << endl; // 20
	cout << "c1 = " << c1 << endl; // 20



    // 3引用做函数参数
    // 形参可以修饰实参
    int a2 = 10;
	int b2 = 20;
    mySwap01(a2, b2);
	cout << "a2:" << a2 << " b2:" << b2 << endl; // 10 20

	mySwap02(&a2, &b2);
	cout << "a2:" << a2 << " b2:" << b2 << endl;   // 20 10

	mySwap03(a2, b2);
	cout << "a2:" << a2 << " b2:" << b2 << endl; // 10 20

    // 4引用做函数返回值
    // 引用是可以作为函数的返回值存在的, 不要返回局部变量引用
    // 函数调用作为左值
    // 不能返回局部变量的引用
    int& ref1 = test01();
    // cout << "ref1 = " << ref1 << endl;  //10
	// cout << "ref1 = " << ref1 << endl;  //0

    // 函数做左值，那么必须返回引用
    int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl; // 20
	cout << "ref2 = " << ref2 << endl; // 20

	test02() = 1000;

	cout << "ref2 = " << ref2 << endl; // 1000
	cout << "ref2 = " << ref2 << endl; // 1000

    // 5引用本质是指针常量
    int a3 = 10;
    
    //自动转换为 int* const ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
	int& ref3 = a3; 
	ref3 = 20; //内部发现ref是引用，自动帮我们转换为: *ref = 20;
    
	cout << "a3:" << a3 << endl;     // 20
	cout << "ref3:" << ref3 << endl; // 20
    
	func(a3);
    cout << "a3:" << a3 << endl;    // 100
	cout << "ref3:" << ref3 << endl; // 100

    // 6常量引用主要用来修饰形参，防止误操作
    // 在函数形参列表中，可以加const修饰形参，防止形参改变实参
    //int& ref = 10;  引用本身需要一个合法的内存空间，因此这行错误
	//加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
	const int& ref4 = 10;

	//ref = 100;  //加入const后不可以修改变量
	cout << ref4 << endl;  // 10

	//函数中利用常量引用防止误操作修改实参
	int a4 = 10;
	showValue(a4);     // 10


    system("pause");

    return 0;
}