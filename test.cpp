#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> mat(3, vector<int>(3));
    // for (int i = 0; i < 3; i++)
    // {
    //     vector<int> temp(3);
    //     for (int j = 0; j < 3; j++)
    //         temp.push_back(0);
    //     mat.push_back(temp);
    // }
    fill(mat.begin(), mat.end(), 0);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << mat[i][j];
        cout << endl;
    }
}