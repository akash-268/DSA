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
    TreeNode(int x) : val(x),
                      left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int> ans;
void KMaxCombinations(vector<int> &A, vector<int> &B, int K)
{
    // sort both arrays A and B
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int N = A.size();

    // Max heap which contains tuple of the format
    // (sum, (i, j)) i and j are the indices
    // of the elements from array A
    // and array B which make up the sum.
    priority_queue<pair<int, pair<int, int>>> pq;

    // my_set is used to store the indices of
    // the  pair(i, j) we use my_set to make sure
    // the indices does not repeat inside max heap.
    set<pair<int, int>> my_set;

    // initialize the heap with the maximum sum
    // combination ie (A[N - 1] + B[N - 1])
    // and also push indices (N - 1, N - 1) along
    // with sum.
    pq.push(make_pair(A[N - 1] + B[N - 1],
                      make_pair(N - 1, N - 1)));

    my_set.insert(make_pair(N - 1, N - 1));

    // iterate upto K
    for (int count = 0; count < K; count++)
    {
        // tuple format (sum, (i, j)).
        pair<int, pair<int, int>> temp = pq.top();
        pq.pop();

        ans.push_back(temp.first);

        int i = temp.second.first;
        int j = temp.second.second;

        int sum = A[i - 1] + B[j];

        // insert (A[i - 1] + B[j], (i - 1, j))
        // into max heap.
        pair<int, int> temp1 = make_pair(i - 1, j);

        // insert only if the pair (i - 1, j) is
        // not already present inside the map i.e.
        // no repeating pair should be present inside
        // the heap.
        if (my_set.find(temp1) == my_set.end())
        {
            pq.push(make_pair(sum, temp1));
            my_set.insert(temp1);
        }

        // insert (A[i] + B[j - 1], (i, j - 1))
        // into max heap.
        sum = A[i] + B[j - 1];
        temp1 = make_pair(i, j - 1);

        // insert only if the pair (i, j - 1)
        // is not present inside the heap.
        if (my_set.find(temp1) == my_set.end())
        {
            pq.push(make_pair(sum, temp1));
            my_set.insert(temp1);
        }
    }
}

vector<int> solve(vector<int> &A, vector<int> &B, int C)
{
    KMaxCombinations(A, B, C);
    vector<int> ret = ans;
    ans.clear();
    return ret;
}

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}