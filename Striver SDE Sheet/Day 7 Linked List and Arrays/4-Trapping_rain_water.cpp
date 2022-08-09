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
int trap(vector<int> &arr)
{
    int n = arr.size();
    int left = 0, right = n - 1;
    int res = 0;
    int maxLeft = 0, maxRight = 0;
    while (left <= right)
    {
        if (arr[left] <= arr[right])
        {
            if (arr[left] >= maxLeft)
                maxLeft = arr[left];
            else
                res += maxLeft - arr[left];
            left++;
        }
        else
        {
            if (arr[right] >= maxRight)
                maxRight = arr[right];
            else
                res += maxRight - arr[right];
            right--;
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
    cout << trap(v);
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
