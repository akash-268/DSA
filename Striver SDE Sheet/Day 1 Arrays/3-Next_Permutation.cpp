#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV

void nextPermutation(vector<int> &a)
{
    int id1 = -1, id2 = -1;
    int n = a.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            id1 = i;
            break;
        }
    }
    if (id1 == -1)
    {
        reverse(a.begin(), a.end());
        return;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > a[id1])
        {
            id2 = i;
            break;
        }
    }
    swap(a[id1], a[id2]);
    int i = id1 + 1, j = n - 1;
    while (i <= j)
    {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}

void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    nextPermutation(v);
    for(auto it:v){
        cout<<it<<" ";
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