#include <iostream>
#include <stack>
#include <locale>
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
    {
        return 0;
    }
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

int main()
{
    string infix = "a*b/c*(d-a%f)";
    cout << "Postfix Form Is: " << inToPost(infix) << endl;
}