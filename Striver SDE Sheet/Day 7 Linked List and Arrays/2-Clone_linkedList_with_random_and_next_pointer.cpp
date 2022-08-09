#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
struct Node
{
    int val;
    Node *next;
    Node *random;
    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
Node *copyRandomList(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        Node *newnode = new Node(temp->val);
        newnode->next = temp->next;
        temp->next = newnode;
        temp = newnode->next;
    }
    temp = head;
    while (temp != NULL)
    {
        temp->next->random = (temp->random) ? (temp->random->next) : NULL;
        temp = temp->next->next;
    }
    Node *original = head;
    Node *clone = head->next;
    Node *result = head->next;
    while (original != NULL)
    {
        original->next = original->next->next;
        clone->next = (clone->next) ? (clone->next->next) : NULL;
        original = original->next;
        clone = clone->next;
    }
    return result;
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