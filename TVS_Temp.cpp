#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// JAI SHREE RAM
// HAR HAR MAHADEV
bool check(vector<int> vec, int elem, int &idx)
{
    idx = -1;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == elem)
        {
            idx = i;
            return true;
        }
    }
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
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int p;
    cin >> p;
    int res = 0, idx = -1;
    for (auto x : b)
    {
        if (check(a, x, idx))
        {
            res += x * p;
            a.erase(a.begin() + idx);
        }
        else
            res -= x * p;
    }
    cout << res;
}
