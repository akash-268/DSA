#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int ans = 0;
    while (t--)
    {
        string s;
        cin >> s;
        map<char, int> mp;
        int flag = 0;
        for (auto i : s)
        {
            mp[i]++;
        }
        if (mp.size() > 2)
            continue;
        if (mp.find('a') == mp.end() || mp.find('b') == mp.end())
            continue;
        int idx;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'b')
            {
                idx = i;
                break;
            }
        }
        for (int i = 0; i < idx; i++)
        {
            if (s[i] != 'a')
            {
                flag = 1;
                break;
            }
        }
        for (int i = idx; i < s.size(); i++)
        {
            if (s[i] != 'b')
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}