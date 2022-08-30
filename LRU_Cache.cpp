#include <bits/stdc++.h>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
class LRUCache
{
public:
    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int k, int v)
        {
            key = k;
            val = v;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    int capacity;
    map<int, node *> mp;
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(node *curr)
    {
        node *temp = head->next;
        head->next = curr;
        curr->next = temp;
        temp->prev = curr;
        curr->prev = head;
    }
    void deletenode(node *temp)
    {
        node *pre = temp->prev;
        node *nex = temp->next;
        pre->next = nex;
        nex->prev = pre;
    }
    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            node *temp = mp[key];
            int res = temp->val;
            mp.erase(key);
            deletenode(temp);
            addnode(temp);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            node *temp = mp[key];
            mp.erase(key);
            deletenode(temp);
        }
        else if (mp.size() == capacity)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        mp[key] = head->next;
    }
};

int main()
{

    int n;
    cin >> n;
    LRUCache *obj = new LRUCache(n);
    int flag = 1;
    do
    {
        cout << "ENTER CHOICE:\n1: To get()\n2: To put()\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "ENTER THE KEY\n";
            int x;
            cin >> x;
            cout << obj->get(x) << endl;
            break;
        case 2:
            cout << "ENTER KEY VALUE PAIR\n";
            int k, v;
            cin >> k >> v;
            obj->put(k, v);
            cout << "PUT SUCCESSFUL\n";
            break;
        }
        cout << "PRESS 'Y' TO REPEAT 'N' TO EXIT\n";
        char ch;
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
            flag = 1;
        else
            flag = 0;
    } while (flag);

    return 0;
}