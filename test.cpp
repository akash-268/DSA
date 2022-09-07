#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    set<ll> st;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll cnt = 0, xor1 = 0;
    st.insert(0);
    for (int i = 0; i < n; i++)
    {
        xor1 = xor1 ^ a[i];
        if (st.count(xor1) >= 1)
        {
            st.clear();
            cnt++;
            st.insert(0);
            xor1 = 0;
        }
        st.insert(xor1);
    }
    cout << cnt << endl;
}

int main()
{
    unordered_map<int, int> mp;
    mp.insert(2, 5);
    mp.insert(1, 51);
    mp.insert(8, 52);
    mp.insert(5, 53);
    mp.insert(10, 2);
    for (auto it : mp)
    {
        cout << it.first << ":" << it.second << endl;
    }
    solve();
}