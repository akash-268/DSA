#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int n1 = -1, n2 = -1, c1 = 0, c2 = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == n1)
            c1++;
        else if (nums[i] == n2)
            c2++;
        else if (c1 == 0)
        {
            n1 = nums[i];
            c1++;
        }
        else if (c2 == 0)
        {
            n2 = nums[i];
            c2++;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    if (n1 == n2)
        return {n1};
    c1 = 0;
    c2 = 0;
    for (auto it : nums)
    {
        if (it == n1)
            c1++;
        if (it == n2)
            c2++;
    }
    if (c1 > n / 3)
        ans.push_back(n1);
    if (c2 > n / 3)
        ans.push_back(n2);
    return ans;
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
    vector<int> ans = majorityElement(v);
    for (auto it : ans)
        cout << it << " ";
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