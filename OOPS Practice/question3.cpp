#include <bits/stdc++.h>
using namespace std;

class Matrix
{
public:
    int r, c;
    vector<vector<int>> mat;

    Matrix(int r1, int c1)
    {
        r = r1;
        c = c1;
        mat.resize(r1, vector<int>(c1, 0));
    }
    int getRows()
    {
        return r;
    }
    int getCol()
    {
        return c;
    }
    void set(int i, int j, int k)
    {
        mat[i][j] = k;
    }
    void addMat(Matrix *ob1, Matrix *ob2)
    {
        if (ob1->getRows() == ob2->getRows() and ob1->getCol() == ob2->getCol())
        {
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    ob1->mat[i][j] += ob2->mat[i][j];
                }
            }
        }
        else
            cout << "Sizes unequal" << endl;
    }
    void mulMat(Matrix *ob1, Matrix *ob2)
    {
        if (ob1->getRows() == ob2->getRows() and ob1->getCol() == ob2->getCol())
        {
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    ob1->mat[i][j] *= ob2->mat[i][j];
                }
            }
        }
        else
            cout << "Sizes unequal" << endl;
    }
    void print(Matrix *obj)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << obj->mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix *obj = new Matrix(3, 3);
    for (int i = 0; i < obj->getRows(); i++)
    {
        for (int j = 0; j < obj->getCol(); j++)
        {
            int x;
            cin >> x;
            obj->set(i, j, x);
        }
    }
    Matrix *obj2 = new Matrix(3, 3);
    for (int i = 0; i < obj2->getRows(); i++)
    {
        for (int j = 0; j < obj2->getCol(); j++)
        {
            int x;
            cin >> x;
            obj2->set(i, j, x);
        }
    }
    obj->addMat(obj, obj2);
    obj->print(obj);
    obj->mulMat(obj, obj2);
    obj->print(obj);
    return 0;
}