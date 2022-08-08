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
ListNode *middleNode(ListNode *head)
{
    int c = 1;
    ListNode *ptr = head;
    while (ptr->next)
    {
        ptr = ptr->next;
        c++;
    }
    c /= 2;
    while (c--)
    {
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