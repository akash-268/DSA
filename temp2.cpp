#include <bits/stdc++.h>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
char *solve(char *str, int k)
{
    int idx;
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        len++;
        if (k > 0)
        {
            if (str[i] == ' ')
            {
                idx = i;
                k--;
            }
        }
    }
    char *res = new char[len + 1];
    int id = 0;
    for (int i = idx + 1; str[i] != '\0'; i++)
    {
        res[id++] = str[i];
    }
    res[id++] = ' ';
    for (int i = 0; i <idx+1; i++)
    {
        res[id++] = str[i];
    }
    res[len] = '\0';
    return res;
}
int main()
{
    char a[50] = "abcd efgf ijkl mnop";
    cout << solve(a, 7) << endl;
}