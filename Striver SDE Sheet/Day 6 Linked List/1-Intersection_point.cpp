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
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // ListNode *ptr1=headA;
    // ListNode *ptr2=headB;
    // int c1=1,c2=1;
    // while(ptr1->next!=NULL){
    //     c1++;
    //     ptr1=ptr1->next;
    // }
    // while(ptr2->next!=NULL){
    //     c2++;
    //     ptr2=ptr2->next;
    // }
    // int diff=abs(c1-c2);
    // ptr1=headA;ptr2=headB;
    // if(c1>c2){
    //     while(diff--){
    //         ptr1=ptr1->next;
    //     }
    // }
    // else{
    //     while(diff--){
    //         ptr2=ptr2->next;
    //     }
    // }
    // while(ptr1 && ptr2){
    //     if(ptr1==ptr2) return ptr1;
    //     ptr1=ptr1->next;
    //     ptr2=ptr2->next;
    // }
    // return NULL;

    ListNode *ptr1 = headA;
    ListNode *ptr2 = headB;
    while (ptr1 != ptr2)
    {
        if (ptr1 == NULL)
            ptr1 = headB;
        else
            ptr1 = ptr1->next;
        if (ptr2 == NULL)
            ptr2 = headA;
        else
            ptr2 = ptr2->next;
    }
    return ptr1;
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