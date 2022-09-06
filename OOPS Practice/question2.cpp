/*

Write a program to print the area and perimeter of a triangle having sides of 3, 4 and 5 units
by creating a class named 'Triangle' with a function to print the area and perimeter.

*/

#include <bits/stdc++.h>
using namespace std;

class Triangle
{
public:
    int a, b, c;
    Triangle(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
    }
    int peri()
    {
        return a + b + c;
    }
    float area()
    {
        float s = (a + b + c) / 2.0;
        // return s;
        double temp = s * (s - a) * (s - b) * (s - c);
        // return temp;
        return sqrt(temp);
        // return area;
    }
};

int main()
{
    Triangle *obj = new Triangle(3, 6, 7);
    cout << obj->peri() << endl;
    cout << obj->area() << endl;
}