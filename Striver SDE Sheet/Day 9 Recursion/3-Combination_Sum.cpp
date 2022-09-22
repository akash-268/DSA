// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> printSubsequences(vector<vector<char>> &res, string s, int index,
                       vector<char> &subarr, int n)
{
    if (index == n)
    {
        vector<char> temp;
        for (auto it : subarr)
        {
            temp.push_back(it);
        }
        res.push_back(temp);
        return res;
    }
    else
    {
        subarr.push_back(s[index]);

        printSubsequences(res, s, index + 1, subarr, n);

        subarr.pop_back();

        // not picking the element into the subsequence.
        printSubsequences(res, s, index + 1, subarr, n);
    }
}

// Driver Code
int main()
{
    vector<vector<char>> res;
    string S = "aabdaabc";
    int K = 3;
    vector<char> vec;
    printSubsequences(res, S, 0, vec, S.size());

    return 0;
}
