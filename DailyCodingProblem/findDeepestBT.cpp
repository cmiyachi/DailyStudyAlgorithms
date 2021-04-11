//
// Created by chris on 4/11/2021.
//
// A C++ program to find value of the deepest node
// in a given binary tree
#include <bits/stdc++.h>
using namespace std;

// A tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// maxLevel : keeps track of maximum level seen so far.
// res : Value of deepest node so far.
// level : Level of root
void find(Node *root, int level, int &maxLevel, int &res)
{
    if (root != NULL)
    {
        find(root->left, ++level, maxLevel, res);

        // Update level and resue
        if (level > maxLevel)
        {
            res = root->data;
            maxLevel = level;
        }

        find(root->right, level, maxLevel, res);
    }
}

// Returns value of deepest node
int deepestNode(Node *root)
{
    // Initialze result and max level
    int res = -1;
    int maxLevel = -1;

    // Updates value "res" and "maxLevel"
    // Note that res and maxLen are passed
    // by reference.
    find(root, 0, maxLevel, res);
    return res;
}

// Driver program
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    cout << deepestNode(root);
    return 0;
}
