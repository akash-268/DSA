#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    vector<Node*>children;
    Node():val(0),children({}){}
    Node(int x):val(x),children({}){}
    Node(int x,vector<Node*>ch):val(x),children(ch){}
};
int main()
{
    Node *root =new Node(5);
    root->children.push_back(new Node(1));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(6));
    root->children[0]->children.push_back(new Node(7));
    root->children[0]->children.push_back(new Node(8));
    root->children[0]->children.push_back(new Node(9));
}