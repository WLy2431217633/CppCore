/*
* 成员函数做友元
*/
#include <iostream>
using namespace std;

class Building;
class goodBoy
{
private:
    /* data */
    Building *building;
public:
    goodBoy(/* args */);
    ~goodBoy();
    void visit(); //只让visit函数作为Building的好朋友，可以发访问Building中私有内容
    void visit2();
};


class Building
{
    //告诉编译器  goodGay类中的visit成员函数 是Building好朋友，可以访问私有内容
    friend void goodBoy::visit();
private:
    /* data */
public:
    Building(/* args */);
    ~Building();

public:
    string m_LivingRoom; //客厅

private:
    string m_BedRoom;    // 卧室

};

Building::Building(/* args */)
{
    this->m_LivingRoom = "客厅";
    this->m_BedRoom = "卧室";
    cout << "Building构造函数" << endl;
}

Building::~Building()
{
    cout << "Building析构函数" << endl;
}

goodBoy::goodBoy(/* args */)
{
    building = new Building;
    cout << "goodBoy构造函数" << endl;
}

goodBoy::~goodBoy()
{
    cout << "goodBoy析构函数" << endl;
}

void goodBoy::visit()
{
    cout << "goodBoy visiting :" << building->m_LivingRoom << endl;
    cout << "goodBoy visiting :" << building->m_BedRoom << endl; // can visit
}

void goodBoy::visit2()
{
    cout << "goodBoy visiting :" << building->m_LivingRoom << endl;
    //cout << "goodBoy visiting :" << building->m_BedRoom << endl; // can't visit
}




void test01()
{
    goodBoy gb;
    gb.visit();
    gb.visit2();
}

int main()
{
    test01();
    system("pause");
    return 0;
}
