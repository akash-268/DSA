#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
struct Node
{
    int data;
    Node *next;
    Node *bottom;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};
Node *mergeTwoLists(Node *a, Node *b)
{

    Node *temp = new Node(0);
    Node *res = temp;

    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }

    if (a)
        temp->bottom = a;
    else
        temp->bottom = b;

    return res->bottom;
}
Node *flatten(Node *root)
{

    if (root == NULL || root->next == NULL)
        return root;
    root->next = flatten(root->next);
    root = mergeTwoLists(root, root->next);
    return root;
}

void solve()
{
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