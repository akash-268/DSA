#include <bits/stdc++.h>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
void mergeArrays(vector<int> arr1, vector<int> arr2, vector<int> &arr3, int n1, int n2)
{
    int i = 0, j = 0, k = 0;

    // Traverse both array
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    // Store remaining elements of first array
    while (i < n1)
        arr3[k++] = arr1[i++];

    // Store remaining elements of second array
    while (j < n2)
        arr3[k++] = arr2[j++];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n), v2(m);
    set<int>st;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        st.insert(v[i]);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> v2[i];
        st.insert(v[i]);
    }
    sort(st.begin(),st.end());
    vector<int>v3;
    for(auto it:st){
        v3.push_back(it);
    }
    int mid = st.size() / 2;
    if (st.size()% 2)
    {
        float ans = v3[mid]/1.0;
        cout << setprecision(2)<<ans;
    }
    else
    {
        float x = v3[mid], y = v3[mid - 1];
        cout << setprecision(2)<<(x + y) / 2.0;
    }
}

int main()
{
    solve();
    return 0;
}