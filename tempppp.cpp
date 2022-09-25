#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string breakPalindrome(string s)
{
    string temp = s;
    bool changed = false;
    if (s.size() == 1)
        return "";
    int i = 0, j = s.size() - 1;
    bool leftA = true;
    bool rightA = true;
    while (i < j)
    {
        if (s[i] != 'a')
        {
            s[i] = 'a';
            return s;
        }
        i++;
        j--;
    }
    s[s.size() - 1] = 'b';
    int x = s.compare(temp);
    if (x)
        return "IMPOSSIBLE";
    return s;
}

int main()
{

    cout << breakPalindrome("aaa");

    return 0;
}