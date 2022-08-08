#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV

int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = nums[0];
    int maxx = nums[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        maxx = max(maxx, dp[i]);
    }
    return maxx;
}

void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int ans=maxSubArray(v);
    cout<<ans<<endl;
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