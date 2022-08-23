int longestPalindrome(string s)
{
    if (s.size() == 1)
        return 1;
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    int c = 0, flag = 0;
    for (auto it : mp)
    {

        if (it.second % 2 == 1)
        {
            flag = 1;
            c++;
        }
    }
    if (flag)
        return s.size() - c + 1;
    return s.size();
}