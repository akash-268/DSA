#include <bits/stdc++.h>
using namespace std;
int priority(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return 0;
}

string inToPost(string infix)
{
    stack<char> stk;
    stk.push('#');
    string postfix = "";
    string::iterator it;

    for (it = infix.begin(); it != infix.end(); it++)
    {
        if (isalnum(char(*it)))
            postfix += *it;
        else if (*it == '(')
            stk.push('(');
        else if (*it == '^')
            stk.push('^');
        else if (*it == ')')
        {
            while (stk.top() != -1 && stk.top() != '(')
            {
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else
        {
            if (priority(*it) > priority(stk.top()))
                stk.push(*it);
            else
            {
                while (stk.top() != '#' && priority(*it) <= priority(stk.top()))
                {
                    postfix += stk.top();
                    stk.pop();
                }
                stk.push(*it);
            }
        }
    }
    while (stk.top() != '#')
    {
        postfix += stk.top();
        stk.pop();
    }

    return postfix;
}
float scanNum(char ch)
{
    int value;
    value = ch;
    return float(value - '0');
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%')
        return 1;
    return 0;
}
int isOperand(char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1;
    return 0;
}
float operation(int a, int b, char op)
{
    if (op == '+')
        return b + a;
    else if (op == '-')
        return b - a;
    else if (op == '*')
        return b * a;
    else if (op == '/')
        return b / a;
    else if (op == '^')
        return pow(b, a);
    else
        return INT_MIN;
}
float postfixEval(string postfix)
{
    int a, b;
    stack<float> stk;
    string::iterator it;
    for (it = postfix.begin(); it != postfix.end(); it++)
    {
        if (isOperator(*it))
        {
            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();
            stk.push(operation(a, b, *it));
        }
        else if (isOperand(*it))
            stk.push(scanNum(*it));
    }
    return stk.top();
}

bool isDigit(string s)
{
    for (auto it : s)
    {
        if (!(it >= '0' && it <= '9'))
            return false;
    }
    return true;
}
bool isEquation(string s)
{
    for (auto it : s)
    {
        if (!(it >= 'a' && it <= 'z'))
            return false;
    }
    return true;
}
int main()
{
    set<int *> st;
    int a[5];
    for (int i = 0; i < 5; i++)
    {
        st.insert(a + i);
    }
    for (auto it : st)
        cout << it << " ";
    cout << endl;
    string s = "a=5,b=6,d=a,c=a+(d-b)";
    vector<string> input;
    stringstream ss(s);
    string temp;
    while (getline(ss, temp, ','))
    {
        input.push_back(temp);
    }
    for (auto it : input)
        cout << it << endl;
    unordered_map<string, int *> mp;
    for (auto it : input)
    {
        int x = it.find("=");
        cout << x << endl;
        if (x != -1)
        {
            string s1 = it.substr(x + 1), s2 = it.substr(0, x);
            cout << s2 << "  " << s1 << endl;
            if (isDigit(s1))
            {
                cout << "All are digits" << endl;
                mp[s2] = *st.begin();
                **st.begin() = stoi(s1);
                st.erase(st.begin());
                unordered_map<string, int *>::iterator it = mp.find(s2);
                cout << it->first << ":" << *it->second << endl;
                for (int i = 0; i < 5; i++)
                {
                    cout << a[i] << " ";
                }
                cout << endl;
                for (auto it : st)
                    cout << it << " ";
                cout << endl;
            }
            else
            {
                cout << "Either equation or initialization" << endl;
                if (!isEquation(s1))
                {
                    cout << "confirm equation" << endl;
                    string equation = "", str1 = "";
                    for (int i = 0; i < s1.size(); i++)
                    {
                        if (s1[i] >= 'a' && s1[i] <= 'z')
                            str1.push_back(s1[i]);
                        else
                        {
                            if (str1.size() > 0 and mp.find(str1) != mp.end())
                            {
                                equation += to_string(*mp[str1]);
                                str1 = "";
                            }

                            equation += s1[i];
                        }
                    }
                    if (str1.size() > 0 and mp.find(str1) != mp.end())
                        equation += to_string(*mp[str1]);
                    cout << equation << endl;
                    string post = inToPost(equation);
                    cout << post << endl;
                    float ans = postfixEval(post);
                    cout << ans << endl;
                    int ans1 = ans;
                    cout << ans1 << endl;
                    mp[s2] = *st.begin();
                    **st.begin() = ans1;
                    st.erase(st.begin());
                    unordered_map<string, int *>::iterator it = mp.find(s2);
                    cout << it->first << ":" << *it->second << endl;
                    for (int i = 0; i < 5; i++)
                    {
                        cout << a[i] << " ";
                    }
                    cout << endl;
                    for (auto it : st)
                        cout << it << " ";
                    cout << endl;
                }
                else
                {
                    cout << "variable to variable initialisation" << endl;
                    mp[s2] = mp[s1];
                    unordered_map<string, int *>::iterator it = mp.find(s2);
                    cout << it->first << ":" << *it->second << endl;
                    for (int i = 0; i < 5; i++)
                    {
                        cout << a[i] << " ";
                    }
                    cout << endl;
                    for (auto it : st)
                        cout << it << " ";
                    cout << endl;
                }
            }
        }
    }
    cout << "\nPrinting Map values.....\n";
    for (auto it : mp)
    {
        cout << it.first << ":" << *it.second << endl;
    }
    cout << "\nPrinting Set values.....\n";
    for (auto it : st)
        cout << it << " ";
}