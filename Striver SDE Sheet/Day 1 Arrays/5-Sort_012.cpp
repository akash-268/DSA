#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
void sortColors(vector<int> &nums)
{
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            c0++;
        else if (nums[i] == 1)
            c1++;
        else
            c2++;
    }
    int k = 0;
    for (int i = 0; i < c0; i++)
        nums[k++] = 0;
    for (int i = 0; i < c1; i++)
        nums[k++] = 1;
    for (int i = 0; i < c2; i++)
        nums[k++] = 2;
    // sort(nums.begin(),nums.end());
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
    sortColors(v);
    for (auto it : v)
    {
        cout << it << " ";
    }
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