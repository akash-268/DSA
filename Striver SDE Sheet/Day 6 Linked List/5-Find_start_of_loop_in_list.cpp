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
ListNode *detectCycle(ListNode *head)
{
    if (!head || !head->next)
        return NULL;
    ListNode *slow = head;
    ListNode *fast = head;
    int flag = 0;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return NULL;
    while (slow != head)
    {
        slow = slow->next;
        head = head->next;
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
