#include <bits/stdc++.h>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int k;
    cin >> k;
    unordered_map<int, int> mp;
    for (auto it : v)
    {
        mp[it] = abs(k - it);
    }
    for (auto it : mp)
        cout << it.first << ": " << it.second << endl;
}