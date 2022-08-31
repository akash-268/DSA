#include <bits/stdc++.h>
#include <memory>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
void print(vector<int> &arr)
{
    for (auto &it : arr)
        cout << it << " ";
    cout << endl;
}

void shuffle(vector<int> &arr)
{

    random_shuffle(arr.begin(), arr.end());
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    shuffle(arr);
    print(arr);
    shuffle(arr);
    print(arr);
    shuffle(arr);
    print(arr);
}