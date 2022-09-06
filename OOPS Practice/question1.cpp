/*

Create a class named 'Student' with a string variable 'name'
and an integer variable 'roll_no'. Assign the value of roll_no as '2'
and that of name as "John" by creating an object of the class Student.

Assign and print the roll number, phone number and address of two students
having names "Sam" and "John" respectively by creating two objects of the class 'Student'.

*/

#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    int roll;
    string name;
    long long int phone;
    string add;
    Student(int n, string s, long long int c, string a)
    {
        roll = n;
        name = s;
        phone = c;
        add = a;
    }
};

int main()
{
    Student *obj1 = new Student(2, "John", 8896021521, "Kanpur,UP");
    Student *obj2 = new Student(1, "Sam", 9555314188, "Bangalore,KA");
    cout << obj1->roll << " " << obj1->phone << " " << obj1->add;
    cout << endl;
    cout << obj2->roll << " " << obj2->phone << " " << obj2->add;
}