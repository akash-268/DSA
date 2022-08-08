#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
int f(vector<int>&v,int k){
    int sum=0,maxi=INT_MIN;
    for(int i=0;i<k;i++) sum+=v[i];
    maxi=max(maxi,sum);
    int i=0;
    while(k<v.size()){
        sum-=v[i];
        sum+=v[k];
        maxi=max(sum,maxi);
        // cout<<maxi<<" ";
        i++;k++;
    }
    return maxi;
}
void solve(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int k;cin>>k;
    cout<<f(v,k);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}