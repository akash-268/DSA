#include <bits/stdc++.h>
#include <memory>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
    class Browser
    {
    public:
        vector<string> url_list;
        int cur = 0;
        Browser(string homepage)
        {
            url_list.push_back(homepage);
        }

        void visit(string url)
        {
            cur++;
            if (cur <= url_list.size() - 1)
            {
                url_list[cur] = url;
                url_list.resize(cur + 1);
            }
            else
                url_list.push_back(url);
        }
        string back(int steps)
        {
            cur -= steps;
            if (cur < 0)
                cur = 0;
            return url_list[cur];
        }

        string forward(int steps)
        {
            cur += steps;
            if (cur > url_list.size() - 1)
                cur = url_list.size() - 1;
            return url_list[cur];
        }
    };
void solve()
{
}

int main()
{
    // int *a = new int();
    // int sum = 0;
    // for (int i = 0; i < 10; i++)
    // {
    //     a[i] = i + 1;
    //     sum += a[i];
    // }
    // cout << sum << endl;

    // string s = "a/b/c/d";
    // stringstream ss(s);
    // string word;
    // while (!ss.eof())
    // {
    //     getline(ss, word, 'b');
    //     cout << word << endl;
    // }
    // stack<shared_ptr<int>> st;
    // auto x1 = make_shared<int>(1);
    // st.push(x1);
    // auto x2 = make_shared<int>(2);
    // st.push(x2);
    // auto x3 = make_shared<int>(3);
    // st.push(x3);
    // while (st.size() != 0)
    // {
    //     cout << *st.top() << " ";
    //     st.pop();
    // }
    // cout << endl;
    // vector<shared_ptr<int>> vt;
    // auto y1 = make_shared<int>(1);
    // vt.push_back(y1);
    // auto y2 = make_shared<int>(2);
    // vt.push_back(y2);
    // auto y3 = make_shared<int>(3);
    // vt.push_back(y3);
    // for (auto &it : vt)
    //     cout << *it << " ";
    // cout << endl;
    // shared_ptr<int> b = make_shared<int>(25);
    // cout << *b << endl;
    // string *str = "abcde";
    unique_ptr<string>  s = make_unique<string>("abcd");
    // s = str;
    cout << *s << endl;
    // unique_ptr<int[]> x = make_unique<int[]>(10);
    // for (int i = 0; i < 10; i++)
    // {
    //     x[i] = i + 1;
    // }
    // for (int i = 0; i < 10; i++)
    //     cout << x[i] << " ";
    return 0;
}