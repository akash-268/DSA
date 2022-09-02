#include <bits/stdc++.h>
#include <memory>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
int main()
{
    list<pair<int, int>> l;
    l.push_back({1, 10});
    l.push_back({2, 20});
    l.push_back({3, 30});
    l.push_back({4, 40});
    l.push_back({2, 20});
    map<int, int> mp;
    mp[1] = 10;
    mp[2] = 20;
    mp[3] = 30;
    mp[4] = 40;
    // vector<pair<int, int>>::iterator i1 = l.begin();
    // cout << i1->first << ":" << i1->second << endl;
    map<int, int>::iterator iter = mp.find(2);
    l.remove({iter->first, iter->second});
    for (auto it : l)
        cout << it.first << ":" << it.second << endl;
}