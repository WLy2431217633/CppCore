/*
* 类做友元
*/
#include <iostream>
using namespace std;




class Building
{

    friend class goodBoy;
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


class goodBoy
{
private:
    /* data */
    Building *building;
public:
    goodBoy(/* args */);
    ~goodBoy();
    void visit();
};

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

void test01()
{
    goodBoy gb;
    gb.visit();
}

int main()
{
    test01();
    system("pause");
    return 0;
}
