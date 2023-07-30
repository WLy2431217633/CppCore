/*
* 全局函数做友元
*/
#include <iostream>
using namespace std;

class Building
{
    void Boy(Building *building);
    friend void goodBoy(Building *building);
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

void Boy(Building *building)
{
    cout << "Boy visiting :" << building->m_LivingRoom << endl;
    // cout << "Boy visiting :" << building->m_BedRoom << endl; // can't visit
}

void goodBoy(Building *building)
{
    cout << "goodBoy visiting :" << building->m_LivingRoom << endl;
    cout << "goodBoy visiting :" << building->m_BedRoom << endl; // can visit
}

void test01()
{
    Building b;
    Boy(&b);
    goodBoy(&b);
}

int main()
{
    test01();
    system("pause");
    return 0;
}
