#include <bits/stdc++.h>
#include <memory>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
void print(vector<int> &arr)
{
    for (auto &it : arr)
        cout << it << " ";
    cout << endl;
}

void shuffle(vector<int> &arr)
{

    random_shuffle(arr.begin(), arr.end());
}
int main()
{
    vector<pair<int, int>> l;
    l.push_back({1, 10});
    l.push_back({2, 20});
    l.push_back({3, 30});
    l.push_back({4, 40});
    l.push_back({5, 50});
    map<int, int> mp;
    mp.insert(1, 10);
    mp.insert(2, 20);
    mp.insert(3, 30);
    mp.insert(4, 40);
    mp.insert(5, 50);
    auto i = mp.find(2);
    vector<pair<int, int>>::iterator i1 = l.begin();
    auto p1 = *(i1);
    cout << p1.first << ":" << p1.second << endl;
}