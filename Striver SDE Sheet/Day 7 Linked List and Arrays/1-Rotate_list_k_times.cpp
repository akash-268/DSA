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
ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next)
        return head;
    int c = 1;
    ListNode *ptr = head;
    while (ptr->next)
    {
        c++;
        ptr = ptr->next;
    }
    if (k > c)
        k = k % c;
    while (k--)
    {
        ListNode *nex = head->next;
        ListNode *cur = head;
        while (nex->next)
        {
            cur = nex;
            nex = nex->next;
        }
        nex->next = head;
        cur->next = NULL;
        head = nex;
    }
    return head;
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
