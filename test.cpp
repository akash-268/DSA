#include <bits/stdc++.h>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
int solve(string s)
{
    int n = s.size();
    vector<int> vis(n, 1);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'X')
            vis[i] = 0;
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'X' && vis[i] == 0)
        {
            c++;
            if (i < n)
                vis[i] = 1;
            if (i + 1 < n)
                vis[i + 1] = 1;
            if (i + 2 < n)
                vis[i + 2] = 1;
        }
    }
    return c;
}

int main()
{
    string s;
    cin >> s;
    cout << solve(s);
}