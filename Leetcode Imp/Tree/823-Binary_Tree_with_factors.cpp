#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
int mod = 1e9 + 7;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int numFactoredBinaryTrees(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    unordered_map<int, long> rootWithCount;
    rootWithCount[arr[0]] = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        long count = 1;
        for (auto j : rootWithCount)
        {
            int rootEle = j.first;
            if (arr[i] % rootEle == 0 && rootWithCount.find(arr[i] / rootEle) != rootWithCount.end())
            {
                count += rootWithCount[rootEle] * rootWithCount[arr[i] / rootEle];
            }
        }
        rootWithCount[arr[i]] = count;
    }
    int noOfTrees = 0;
    for (auto i : rootWithCount)
    {
        noOfTrees = (noOfTrees + i.second) % mod;
    }
    return noOfTrees;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << numFactoredBinaryTrees(v);
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