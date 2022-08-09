#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
vector<vector<int>> threeSum(vector<int> &a)
{
    vector<vector<int>> res;
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size() - 2; i++)
    {
        if (i == 0 || (i > 0 && a[i] != a[i - 1]))
        {
            int lo = i + 1, hi = a.size() - 1, mid = 0 - a[i];
            while (lo < hi)
            {
                if (a[lo] + a[hi] == mid)
                {
                    vector<int> temp;
                    temp.push_back(a[i]);
                    temp.push_back(a[lo]);
                    temp.push_back(a[hi]);
                    res.push_back(temp);
                    while (lo < hi && a[lo] == a[lo + 1])
                        lo++;
                    while (lo < hi && a[hi] == a[hi - 1])
                        hi--;
                    lo++;
                    hi--;
                }
                else if (a[lo] + a[hi] < mid)
                {
                    lo++;
                }
                else
                    hi--;
            }
        }
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<int>> res = threeSum(v);
    for (auto it : res)
    {
        cout << "[ ";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "]" << endl;
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
