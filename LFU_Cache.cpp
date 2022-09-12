#include <bits/stdc++.h>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
struct node
{
    int key, value, cnt;
    node *next;
    node *prev;
    node(int k, int v)
    {
        key = k;
        value = v;
        cnt = 1;
    }
};
struct List
{
    int size;
    node *head;
    node *tail;
    List()
    {
        head = new node(0, 0);
        tail = new node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void add(node *nod)
    {
        node *temp = head->next;
        head->next = nod;
        nod->next = temp;
        temp->prev = nod;
        nod->prev = head;
        size++;
    }
    void remove(node *nod)
    {
        node *pre = nod->prev;
        node *nex = nod->next;
        pre->next = nex;
        nex->prev = pre;
        size--;
    }
};
class LFUCache
{
public:
    int size, minfreq, cursize;
    map<int, node *> mp;
    map<int, List *> freqlist;
    LFUCache(int capacity)
    {
        size = capacity;
        minfreq = 0;
        cursize = 0;
    }

    /*  agar koi node ko touch kiya toh jo jo operation karte hai-> map se delete karna list se delete karna
        phir uski freq badhana aur vapis se list mein add karna aur map mein add karna voh sab kiya */
    void touched(node *node)
    {
        // map se erase kiya
        mp.erase(node->key);
        // frequency list wale map mein jis bhi jagah pada tha node vahan se delete kiya
        freqlist[node->cnt]->remove(node);
        // check kiya kahin map khali toh nahi ho gaya, if yes increase minimum frequency
        if (node->cnt == minfreq && freqlist[node->cnt]->size == 0)
            minfreq++;
        
        List *newFreq = new List(); // nayi empty list banayi
        // agar jis index pe node jayega vahan pe list padi hai toh
        if (freqlist.find(node->cnt + 1) != freqlist.end())
        {
            newFreq = freqlist[node->cnt + 1]; // nayi list ko usse assign kiya
        }
        node->cnt += 1;                // node ka count badhaya kyuki usko touch kiye humlog uski frequency badh gyi
        newFreq->add(node);            // apni newly created list mein add kar diya usko
        freqlist[node->cnt] = newFreq; // end mein apni newly created list ko map mein daal diya
        mp[node->key] = node;          // map mein vapis se entry kar di
    }

    /*  map mein agar node pada hota hai toh uss node ki jo bhi count(freq) hai uss freq pe jo list
        hai usme se node ko hata ke front pe le aaye aur val return kar di else -1 return kiya */
    int get(int key)
    {
        // check if key is there in map or not
        if (mp.find(key) != mp.end())
        {                          // if yes ->
            node *temp = mp[key];  // jo bhi node pada hai uss key pe usko nikala
            int val = temp->value; // value store karayi uski
            touched(temp);         // humlog node ko chuye hai toh touched call kiya
            return val;            // value return ki
        }
        return -1; // agar nahi mila map mein toh -1 return
    }

    /*  agar map mein pehle se pada hai toh uski value update hogi varna->
        check kiya agar cache full hai toh min freq wali list se LRU delete kiya, 
        phir min freq wali list mein apna new node bana ke add kiya */
    void put(int key, int value)
    {
        if (size == 0)
            return; // leetcode ka edge case
        // check if the key already in map means put(1,10) -> check if 1 is already in map
        if (mp.find(key) != mp.end())
        {                         // if yes->
            node *temp = mp[key]; // uss key pe jo bhi node pada hai usko nikaal ke temp mein store kiya
            temp->value = value;  // uss node ki value update kari
            touched(temp);        // we accessed that node therefore touched ko call kiya
        }
        else
        {
            if (cursize == size)
            {                                                            // check if currsize(size of cache) agar full hai
                List *list_of_min_freq = freqlist[minfreq];              // min freq wali list uthayi map se
                mp.erase(list_of_min_freq->tail->prev->key);             // mp mein se uss list ke last element ko delete kiya
                freqlist[minfreq]->remove(list_of_min_freq->tail->prev); // list se bhi delete kiya usi node ko
                cursize--;                                               // delete karne pe cache ki size decrese hogi so, cursize-- kiya
            }
            cursize++;                  // ek node humlog add karne jaa rahe hai so, cache ka size ek se increase kiya
            minfreq = 1;                // new element hai toh voh humesha frequency 1 pe hi add hoga
            List *newlist = new List(); // ek new list banayi
            if (freqlist.find(minfreq) != freqlist.end())
            {                                // agar freq 1 pe koi list pehle se padi hai toh ->
                newlist = freqlist[minfreq]; // existing list ko new list mein copy kiya
            }
            node *newnode = new node(key, value); // ek node banaya with the given key and value
            newlist->add(newnode);                // uss node ko add kiya in that newlist
            freqlist[minfreq] = newlist;          // updated list ko copy kara diya min freq pe
            mp[key] = newnode;                    // naya node add kiya hai toh voh map mein bhi add hoga
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */