#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// JAI SHREE RAM
// HAR HAR MAHADEV
bool check(vector<int> vec, int elem)
{
    if (find(vec.begin(), vec.end(), elem) != vec.end())
        return true;
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    sort(a.begin(), a.end());
    int res = 0;
    if (n > m)
        res = a[n - m - 1] + 1;
    if (n == m)
        res = a[n - m] - 1;
    if (res > 1)
        cout << res;
    else
        cout << 0;
}