#include <bits/stdc++.h>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
// int binarySearchCount(int arr[], int n, int key)
// {
//     int left = 0;
//     int right = n - 1;

//     int count = 0;

//     while (left <= right)
//     {
//         int mid = (right + left) / 2;
//         if (arr[mid] <= key)
//         {
//             count = mid + 1;
//             left = mid + 1;
//         }
//         else
//             right = mid - 1;
//     }

//     return count;
// }

// int solve(vector<int> cost,int n,vector<int>e1,vector<int>e2){
//     vector<pair<int,int>>adj[n];
//     for(int i=0;i<cost.size();i++){
//         adj[e1[i]].push_back({e2[i],cost[i]});
//     }
    
// }

int maxPerksItems(int catridges,int dollars,int recycleReward,int perksCost){
    int ans = min(catridges, dollars / perksCost);
    while (catridges > 0)
    {
        catridges--;
        dollars += recycleReward;
        ans = max(ans, min(catridges, dollars / perksCost));
    }
    return ans;
}

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout << maxPerksItems(a, b, c, d);
}