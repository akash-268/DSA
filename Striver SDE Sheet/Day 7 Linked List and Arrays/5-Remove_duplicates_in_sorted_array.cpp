#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
int removeDuplicates(vector<int> &nums)
{
    // map<int, int> mp;
    // for (auto it : nums)
    //     mp[it]++;
    // nums.clear();
    // for (auto it : mp)
    //     nums.push_back(it.first);
    // return mp.size();

    if (nums.size() == 0)
        return {};
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[j] != nums[i])
        {
            nums[j + 1] = nums[i];
            j++;
        }
    }
    return j + 1;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << removeDuplicates(v);
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