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
int main()
{
    int a = 5, b = 6, c = 7, d = 8;
    map<string, int> mp;
    mp.insert({"var1", 5});
    mp.insert({"var2", 6});
    mp.insert({"var3", 7});
    mp.insert({"var4", 8});

    string s;
    cin >> s;

    int x = s.find("=");
    
    cout << endl
         << "index: " << x << endl;

    string s1 = s.substr(x + 1), s2 = s.substr(0, x);
    cout << endl
         << s2 << endl
         << s1 << endl;
    string new_str = "", op = "";
    int idx;
    for (int i = 0; i < s1.size(); i++)
    {
        if (isOperator(s1[i]))
        {

            new_str += to_string(mp[op]);
            new_str += s1[i];
            op = "";
            idx = i;
        }
        else
            op.push_back(s1[i]);
    }
    new_str += to_string(mp[s1.substr(idx + 1)]);
    cout << new_str << endl;
    string post = inToPost(new_str);
    cout << endl
         << post << endl;

    float ans = postfixEval(post);
    cout << endl
         << ans << endl;
}