#include <bits/stdc++.h>
#include <memory>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV

int main()
{
    string s = "I am Akash from Kanpur";
    s += " ";
    string ans;
    stack<string> st;
    for (auto i = 0; i < s.size(); i++)
    {
        ans.push_back(s[i]);
        if (s[i] == ' ')
        {
            st.push(ans);
            ans = "";
        }
    }
    string ans2;
    while (!st.empty())
    {
        string temp = st.top();
        ans2 += temp;
        st.pop();
    }
    cout << ans2 << " ";
}