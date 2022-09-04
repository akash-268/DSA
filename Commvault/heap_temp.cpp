#include <bits/stdc++.h>
#include <memory>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
int main()
{
    priority_queue<int, vector<int>, greater<int>> pq; //ascending order
    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}