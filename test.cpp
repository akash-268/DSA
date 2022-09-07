#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, int> mp;
    mp.insert(2, 5);
    mp.insert(1, 51);
    mp.insert(8, 52);
    mp.insert(5, 53);
    mp.insert(10, 2);
    for (auto it : mp)
    {
        cout << it.first << ":" << it.second << endl;
    }
}