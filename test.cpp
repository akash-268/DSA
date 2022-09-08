#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int *ptr;
    int v;
    ptr = &v;
    v = (int)ptr;
    printf("%d\n", v);
    ptr++;
    v++;
    printf("%d %d\n", v, ptr);
}