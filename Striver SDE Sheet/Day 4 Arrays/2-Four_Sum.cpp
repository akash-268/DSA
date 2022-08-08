#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 1; i++)
    {
        long long int t1 = target - nums[i];
        for (int j = i + 1; j < n; j++)
        {
            long long int t2 = t1 - nums[j];
            long long int left = j + 1, right = n - 1;
            while (left < right)
            {
                long long int sum = nums[left] + nums[right];
                if (sum == t2)
                {
                    vector<int> v(4, 0);
                    v[0] = nums[i];
                    v[1] = nums[j];
                    v[2] = nums[left];
                    v[3] = nums[right];
                    res.push_back(v);
                    while (left < right && nums[left] == v[2])
                        left++;
                    while (left < right && nums[right] == v[3])
                        right--;
                }
                else if (sum < t2)
                    left++;
                else
                    right--;
            }
            while (j + 1 < n && nums[j + 1] == nums[j])
                j++;
        }
        while (i + 1 < n - 1 && nums[i + 1] == nums[i])
            i++;
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
    int k;
    cin >> k;
    vector<vector<int>> res = fourSum(v, k);
    for (auto it : res)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
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