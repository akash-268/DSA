#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV

int majorityElement(vector<int> &nums)
{
    int c = 0, el = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (c == 0)
            el = nums[i];
        if (el == nums[i])
            c++;
        else
            c--;
    }
    return el;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << majorityElement(v);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    while (t--)
    {
        solve();
    }
}