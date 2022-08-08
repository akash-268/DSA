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
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *ptr = new ListNode();
    ptr->next = head;
    ListNode *fast = ptr;
    ListNode *slow = ptr;
    int k = n;
    while (k--)
    {
        fast = fast->next;
    }
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return ptr->next;
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