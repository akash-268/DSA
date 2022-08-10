#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
string fractionToDecimal(int numerator, int denominator)
{
    if (!numerator)
        return "0";
    string ans = "";
    if (numerator > 0 ^ denominator > 0)
        ans += '-';
    long num = labs(numerator), den = labs(denominator);
    long q = num / den;
    long r = num % den;
    ans += to_string(q);
    if (r == 0)
        return ans;
    ans += '.';
    unordered_map<long, int> mp;
    while (r != 0)
    {
        if (mp.find(r) != mp.end())
        {
            int pos = mp[r];
            ans.insert(pos, "(");
            ans += ')';
            break;
        }
        else
        {
            mp[r] = ans.length();
            r *= 10;
            q = r / den;
            r = r % den;
            ans += to_string(q);
        }
    }
    return ans;
}
void solve()
{
    int n,d;cin>>n>>d;
    cout<<fractionToDecimal(n,d);
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