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
ListNode *reverseList(ListNode *head)
{
    ListNode *curr = NULL;
    while (head)
    {
        ListNode *next = head->next;
        head->next = curr;
        curr = head;
        head = next;
    }
    return curr;
}
bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    if (head->next->next == NULL)
    {
        return head->val == head->next->val;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *dummy = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverseList(slow->next);
    slow = slow->next;
    while (slow)
    {
        if (slow->val != dummy->val)
            return false;
        slow = slow->next;
        dummy = dummy->next;
    }
    return true;
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