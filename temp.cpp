#include <bits/stdc++.h>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
#define ll long long int
void subArraySum(vector<int> arr, int n, int sum)
{
    int x, i, j, ans = INT_MIN;
    for (i = 0; i < n; i++)
    {
        int c = 0;
        x = arr[i];
        for (j = i + 1; j <= n; j++)
        {
            if (x < sum)
                c++;
            if (x >= sum || j == n)
            {
                ans = max(ans, c);
                break;
            }
            x = x + arr[j];
        }
    }
    cout << ans;
    return;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum;
    cin >> sum;
    subArraySum(arr, n, sum);
    return 0;
}