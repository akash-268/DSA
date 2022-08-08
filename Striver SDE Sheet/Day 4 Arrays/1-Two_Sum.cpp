#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> res;
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(target - nums[i]) != mp.end())
        {
            res.push_back(i);
            res.push_back(mp[target - nums[i]]);
            return res;
        }
        mp[nums[i]] = i;
    }
    return res;
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
    int k;
    cin >> k;
    vector<int> ans = twoSum(v, k);
    cout << '[' << ans[0] << "," << ans[1] << "]";
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