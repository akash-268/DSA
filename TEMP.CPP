#include <bits/stdc++.h>

using namespace std;

map<char, int> mp;

bool static comp(string &s1, string &s2)
{ 
    int m = s1.length();
    int n = s2.length();
    for (int i = 0; i < min(m, n); i++)
    {
        if (mp[s1[i]] == mp[s2[i]])
            continue;
        else if (mp[s1[i]] < mp[s2[i]])
            return true;
        else
            return false;
    }
    if (s1.length() < s2.length())
        return true;
    else
        return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
            mp[s[i]] = i + 1;
        int n;
        cin >> n;
        vector<string> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];
        sort(vec.begin(), vec.end(), comp);
        for (int i = 0; i < n; i++)
            cout << vec[i] << endl;
        mp.clear();
    }
    return 0;
}