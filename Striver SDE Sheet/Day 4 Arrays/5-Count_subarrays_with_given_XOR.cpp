#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
int XOR(vector<int> &A, int B)
{
    map<int, int> mp;
    int x = 0;
    long long c = 0;
    for (int i = 0; i < A.size(); i++)
    {
        x ^= A[i];
        if (x == B)
            c++;
        int h = x ^ B;
        if (mp.find(h) != mp.end())
        {
            c = c + mp[h];
        }
        mp[x]++;
    }
    return c;
}
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int k;cin>>k;
    cout<<XOR(v,k);
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