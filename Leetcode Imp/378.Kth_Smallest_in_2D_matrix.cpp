#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
int m, n;
int countLessOrEqual(vector<vector<int>> &matrix, int x)
{
    int cnt = 0, c = n - 1;
    for (int r = 0; r < m; ++r)
    {
        while (c >= 0 && matrix[r][c] > x)
            --c;
        cnt += (c + 1);
    }
    return cnt;
}
int kthSmallest(vector<vector<int>> &matrix, int k)
{
    m = matrix.size(), n = matrix[0].size();
    int left = matrix[0][0], right = matrix[m - 1][n - 1], ans = -1;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (countLessOrEqual(matrix, mid) >= k)
        {
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }
    int k;
    cin >> k;
    cout << kthSmallest(v, k);
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