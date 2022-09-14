#include <bits/stdc++.h>
#include <memory>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};
bool checkperfectsquare(int n)
{
    if (ceil((double)sqrt(n)) == floor((double)sqrt(n)))
        return true;
    else
        return false;
}
int countCustomers(vector<int> bill)
{
    int answer = 0;
    for (int it : bill)
    {
        if (checkperfectsquare(it))
            answer++;
    }
    return answer;
}
int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout << countCustomers(v);
}

struct Node *newNode(int data)
{
    struct Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
struct Node *reverseList(struct Node *head)
{
    struct Node *curr = NULL;
    while (head)
    {
        struct Node *next = head->next;
        head->next = curr;
        curr = head;
        head = next;
    }
    return curr;
}
struct Node *AddTwoNumbers(struct Node *list1, struct Node *list2)
{
    struct Node *ptr = newNode(0);
    struct Node *dummy = ptr;
    int carry = 0;
    while (list1 || list2 || carry)
    {
        int sum = 0;
        if (list1 != NULL)
        {
            sum += list1->data;
            list1 = list1->next;
        }
        if (list2 != NULL)
        {
            sum += list2->data;
            list2 = list2->next;
        }
        sum += carry;
        carry = sum / 10;
        struct Node *node = newNode(sum % 10);
        ptr->next = node;
        ptr = ptr->next;
    }
    return reverseList(dummy->next);
}