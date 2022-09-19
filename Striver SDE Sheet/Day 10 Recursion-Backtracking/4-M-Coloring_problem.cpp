#include <bits/stdc++.h>
using namespace std;
bool check(int node, int col, int n, vector<vector<int>> &graph, int color[])
{
    for (int i = 0; i < n; i++) // check for all the adjacent nodes
    {
        if (i != node && graph[i][node] == 1 && color[i] == col) // agar i adjacent node hai aur same color ka ai toh false
            return false;
    }
    // else true
    return true;
}
bool solve(int node, vector<vector<int>> &graph, int color[], int n, int m)
{
    if (node == n) // agar saare node color ho chuke hai toh true
        return true;
    for (int i = 1; i <= m; i++)
    {
        if (check(node, i, n, graph, color)) // check whether we can paint vertex [node] with color i
        {
            color[node] = i;
            if (solve(node + 1, graph, color, n, m)) // recursion
                return true;
            color[node] = 0; // backtracking -> remove kiya color recursion fail hone pe
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &graph, int m)
{
    // Write your code here
    int n = graph.size();
    int color[n] = {0};
    if (solve(0, graph, color, n, m))
        return "YES";
    else
        return "NO";
}
int main()
{
    return 0;
}