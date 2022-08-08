#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
pair<int,int> fun(vector<int>&a){
    int n=a.size();
    int s1=(n*(n+1))/2;
    int p1=(n*(n+1)*((2*n)+1))/6;
    int sum=0,p2=0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        p2+=a[i]*a[i];
    }
    int missing=(sum-s1+(p1-p2)/(sum-s1))/2;
    int repeat=missing-(sum-s1);
    return {-missing,-repeat};
}
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    pair<int,int> ans=fun(v);
    cout<<ans.first<<" "<<ans.second<<endl;
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