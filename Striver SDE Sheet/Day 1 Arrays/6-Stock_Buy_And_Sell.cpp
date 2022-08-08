#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
int maximumProfit(vector<int> &prices)
{
    int maxi = 0, mini = INT_MAX;
    for (int i = 0; i < prices.size(); i++)
    {
        mini = min(mini, prices[i]);
        maxi = max(maxi, prices[i] - mini);
    }
    return maxi;
}
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int ans=maximumProfit(v);
    cout<<ans;
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