//
// Created by chris on 4/11/2021.
//
#include <bits/stdc++.h>
using namespace std;

struct Node
{
   vector<Node *> children;
   int weight  = 0;
};

pair<int,int> longest_height_and_path(Node *root)
{
    pair<int,int> result;
    int longest_path_so_far = INT_MIN;
    int highest = 0, second_highest = 0;
    int ch_length = root->children.size();

    for (int i = 0; i < ch_length; i++)
    {
        Node *child = root->children[i];
        int weight = child->weight;
        result = longest_height_and_path(child);
        longest_path_so_far = max(longest_path_so_far, result.second);
        if (result.first + weight > highest)
        {
            second_highest = highest;
            highest = result.first + weight;
        }
        else if (result.first + weight > second_highest)
        {
            second_highest = result.first + weight;
        }
    }

    result.first = highest;
    result.second = max(longest_path_so_far, highest + second_highest);
    return result;
}

int longestPath(Node *root)
{
    pair<int,int> pathAndHeight;
    pathAndHeight = longest_height_and_path(root);
    return pathAndHeight.second;
}
/*
 * This problem was asked by Uber.

Given a tree where each edge has a weight, compute the length of the longest path in the tree.

For example, given the following tree:

   a
  /|\
 b c d
    / \
   e   f
  / \
 g   h
and the weights: a-b: 3, a-c: 5, a-d: 8, d-e: 2, d-f: 4, e-g: 1, e-h: 1, the longest path would be c -> a -> d -> f, with a length of 17.

The path does not have to pass through the root, and each node can have any amount of children.
 */
int main(void)
{
    Node a;
    a.weight = 0;
    Node b;
    b.weight = 3;
    a.children.push_back(&b);
    Node c;
    c.weight = 5;
    a.children.push_back(&c);
    Node d;
    d.weight = 8;
    a.children.push_back(&d);
    Node e;
    e.weight = 2;
    d.children.push_back(&e);
    Node f;
    f.weight = 4;
    d.children.push_back(&f);
    Node g;
    g.weight = 1;
    e.children.push_back(&g);
    Node h;
    h.weight = 1;
    e.children.push_back(&h);
    cout << longestPath(&a);

    return 0;
}