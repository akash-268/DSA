#include <bits/stdc++.h>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
int solve(vector<int> &a)
{
    sort(a.begin(),a.end());
    int n = a.size();
    vector<int> temp;
    temp.push_back(a[0] + a[1]);
    for (int i = 2; i < n; i++)
    {
        int x = temp[temp.size() - 1];
        temp.push_back(x + a[i]);
    }
    int sum = 0;
    for (auto it : temp)
    {
        sum += it;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << solve(v);
}