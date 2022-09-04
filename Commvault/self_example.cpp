#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    int a;
    A(int x)
    {
        a = x;
    }
    void setA(int x)
    {
        a = x;
    }
    int getA()
    {
        return a;
    }
    ~A() {}
};

class B
{
public:
    int b;
    B(int x)
    {
        b = x;
    }
    void setB(int x)
    {
        b = x;
    }
    int getsA(A *obj)
    {
        obj->getA();
    }
    int getB()
    {
        return b;
    }
    ~B() {}
};

int main()
{
    B *obj = new B(5);
    A *ob = new A(10);
    int ans = obj->getsA(ob);
    cout << ans << endl;
    delete ob;
    delete obj;
}