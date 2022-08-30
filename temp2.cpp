#include <bits/stdc++.h>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
int binary_search(vector<int> &v, int k)
{
    int start = 0, end = v.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (v[mid] == k)
            return mid;
        else if (v[mid] > k)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return end;
}
int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int k;
    cin >> k;
    map<int, int> mp;
    for (auto it : v)
    {
        mp[it] = abs(k - it);
    }
    for (auto it : mp)
        cout << it.first << ": " << it.second << endl;
}