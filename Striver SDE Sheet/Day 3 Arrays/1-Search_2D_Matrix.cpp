#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV

// bool binary(vector<int>&a,int k){
//     int i=0,j=a.size()-1;
//     while(i<=j){
//         int mid=i+(j-i)/2;
//         if(a[mid]==k) return true;
//         else if(a[mid]<k) i=mid+1;
//         else j=mid-1;
//     }
//     return false;
// }
// bool searchMatrix(vector<vector<int>>& a, int target) {
//    for(auto it:a){
//        if(binary(it,target)) return true;
//    }
//     return false;
// }
bool searchMatrix(vector<vector<int>> &a, int target)
{
        int i = 0, j = a[0].size() - 1;
        while (j >= 0 && i < a.size())
        {
            if (target == a[i][j])
                return true;
            else if (target > a[i][j])
                i++;
            else
                j--;
        }
        return false;
}
void solve()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> v(m,vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }
    int k;
    cin >> k;
    cout << searchMatrix(v, k);
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