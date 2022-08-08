#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
int Merge(vector<int> &nums, int low, int mid, int high)
{
    int total = 0;
    int j = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (j <= high && nums[i] > 2LL * nums[j])
        {
            j++;
        }
        total += (j - (mid + 1));
    }

    vector<int> t;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {

        if (nums[left] <= nums[right])
        {
            t.push_back(nums[left++]);
        }
        else
        {
            t.push_back(nums[right++]);
        }
    }

    while (left <= mid)
    {
        t.push_back(nums[left++]);
    }
    while (right <= high)
    {
        t.push_back(nums[right++]);
    }

    for (int i = low; i <= high; i++)
    {
        nums[i] = t[i - low];
    }
    return total;
}
int MergeSort(vector<int> &nums, int low, int high)
{

    if (low >= high)
        return 0;
    int mid = (low + high) / 2;
    int inv = MergeSort(nums, low, mid);
    inv += MergeSort(nums, mid + 1, high);
    inv += Merge(nums, low, mid, high);
    return inv;
}
int reversePairs(vector<int> &arr)
{
    return MergeSort(arr, 0, arr.size() - 1);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << reversePairs(v);
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