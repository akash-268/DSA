#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    virtual void show()
    {
        cout << "Base Class" << endl;
    }
};

class B : public A
{
public:
    void show()
    {
        cout << "derived class" << endl;
    }
};

int main()
{
    A base;
    A *obj;
    B ob;
    obj = &ob;
    obj->show();
    ob.show();
    base.show();
}