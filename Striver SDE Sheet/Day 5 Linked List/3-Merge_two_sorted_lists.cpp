
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
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    if (l1->val > l2->val)
        swap(l1, l2);
    ListNode *res = l1;
    while (l1 && l2)
    {
        ListNode *temp = NULL;
        while (l1 != NULL && l1->val <= l2->val)
        {
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        swap(l1, l2);
    }
    return res;
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