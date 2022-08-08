#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 and j >= 0)
    {
        if (nums1[i] < nums2[j])
            nums1[k--] = nums2[j--];
        else
            nums1[k--] = nums1[i--];
    }
    while (j >= 0)
        nums1[k--] = nums2[j--];
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v1(n + m);
    vector<int> v2(n);
    for (int i = 0; i < m; i++)
        cin >> v1[i];
    for (int i = m; i < v1.size(); i++)
        v1[i] = 0;
    // for(auto it:v1) cout<<it<<" ";
    // cout<<"------------------------\n";
    for (int i = 0; i < n; i++)
        cin >> v2[i];
    // for (auto it : v2)
    //     cout << it << " ";
    // cout << "------------------------\n";
    merge(v1, n, v2, m);
    for (auto it : v1)
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