#include <bits/stdc++.h>
#include <memory>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV

void solve()
{
}

int main()
{
    int *a = new int();
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        a[i] = i + 1;
        sum += a[i];
    }
    cout << sum << endl;

    string s1 = "a/b/c/d";
    stringstream ss(s1);
    string word;
    while (!ss.eof())
    {
        getline(ss, word, '/');
        cout << word << endl;
    }
    stack<shared_ptr<int>> st;
    auto x1 = make_shared<int>(1);
    st.push(x1);
    auto x2 = make_shared<int>(2);
    st.push(x2);
    auto x3 = make_shared<int>(3);
    st.push(x3);
    while (st.size() != 0)
    {
        cout << *st.top() << " ";
        st.pop();
    }
    cout << endl;
    vector<shared_ptr<int>> vt;
    // cout << "\nEnter values of vector:\n";
    auto y1 = make_shared<int>(1);
    vt.push_back(y1);
    auto y2 = make_shared<int>(2);
    vt.push_back(y2);
    auto y3 = make_shared<int>(3);
    vt.push_back(y3);
    // for (int i = 1; i <= 3; i++)
    // {
    //     int x;
    //     cin >> x;
    //     vt.push_back(make_shared<int>(x));
    // }
    for (auto &it : vt)
        cout << *it << " ";
    cout << endl;
    shared_ptr<int> b = make_shared<int>(25);
    cout << *b << endl;
    char *str = "abcde";
    unique_ptr<string> s = make_unique<string>("abcd");
    /*
     *s = str;
     */
    cout << *s << endl;
    unique_ptr<int[]> x = make_unique<int[]>(100);
    for (int i = 0; i < 100; i++)
    {
        x[i] = i + 1;
    }
    for (int i = 0; i < 100; i++)
        cout << x[i] << " ";
    return 0;
}