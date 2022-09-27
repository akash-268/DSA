#include <bits/stdc++.h>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
#define ll long long int
#define vin vector<int>
#define f(i, a, b) for (ll i = a; i < b; i++)
#define rf(i, a, b) for (ll i = a; i >= b; i--)
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define vc vector
#define fi first
#define se second
#define all(x) x.begin(), x.end()
const int maxi = 1e5 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ll eps = 1e-9;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<vector<int>> ans;
void solve(vector<int> arr, int i, vector<int> temp, int k)
{
    if (i == arr.size())
    {
        if (k == 0)
            ans.push_back(temp);
        return;
    }
    if (arr[i] <= k)
    {
        temp.push_back(arr[i]);
        solve(arr, i, temp, k - arr[i]);
        temp.pop_back();
    }
    solve(arr, i + 1, temp, k);
}
vector<vector<int>> combinationSum(vector<int> &nums, int target)
{
    vector<int> temp;
    solve(nums, 0, temp, target);
    return ans;
}
int moveApples(int input1, int input2[])
{
    long long avg = 0;
    for (int i = 0; i < input1; i++)
    {
        avg += input2[i];
    }
    avg /= input1;
    long long temp = 0;
    for (int i = 0; i < input1; i++)
    {
        temp += abs(input2[i] - avg);
    }
    return temp / 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    // cin >> t;
    int arr[2] = {1, 3};
    cout << moveApples(2, arr);
}