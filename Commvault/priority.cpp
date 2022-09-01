#include <bits/stdc++.h>
#include <memory>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV

class process
{
public:
    int priority;
    string name;
    int id;
    process(int x, int id, string n)
    {
        priority = x;
        name = n;
        this->id = id;
    }
};
struct cmp
{

    bool operator()(process *p1, process *p2)
    {
        return p1->priority > p2->priority;
    }
};
int main()
{
    priority_queue<process *, vector<process *>, cmp> pq;
    for (int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        int idx;
        cin >> idx;
        string s;
        cin >> s;
        process *obj = new process(x, idx, s);
        pq.push(obj);
    }
    while (pq.empty() != true)
    {
        cout << pq.top()->priority << "---" << pq.top()->id << "---" << pq.top()->name << endl;
        pq.pop();
    }
}