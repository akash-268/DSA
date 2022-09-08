#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class student
{
public:
    string name;
    int age;
    int roll;
    student(string s, int a, int r)
    {
        name = s;
        age = a;
        roll = r;
    }
};

int main()
{
    student ob("akash", 22, 25636);
    cout << &ob << endl
         << ob.name << " " << ob.age << " " << ob.roll << endl;
    student *ob2 = &ob;
    cout << &ob2 << endl
         << ob2->name << " " << ob2->age << " " << ob2->roll;
}