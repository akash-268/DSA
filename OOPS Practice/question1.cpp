/*

Create a class named 'Student' with a string variable 'name' 
and an integer variable 'roll_no'. Assign the value of roll_no as '2' 
and that of name as "John" by creating an object of the class Student.

*/

#include<bits/stdc++.h>
using namespace std;
class Student{
    public:
        int roll;
        string name;
    Student(int n,string s){
        roll=n;
        name=s;
    }
};

int main(){
    Student* obj=new Student(2,"John");
}