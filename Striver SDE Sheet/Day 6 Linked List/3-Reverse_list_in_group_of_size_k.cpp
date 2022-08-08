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
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head || k == 1)
        return head;
    int c = 0;
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *cur = dummy, *nex = dummy, *pre = dummy;
    while (cur->next != NULL)
    {
        c++;
        cur = cur->next;
    }
    while (c >= k)
    {
        cur = pre->next;
        nex = cur->next;
        for (int i = 1; i < k; i++)
        {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        c -= k;
        pre = cur;
    }
    return dummy->next;
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