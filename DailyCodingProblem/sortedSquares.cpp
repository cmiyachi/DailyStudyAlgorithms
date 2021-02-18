//
// Created by chris on 2/17/2021.
/* This problem was asked by Google.

Given a sorted list of integers, square the elements and give the output in sorted order.

For example, given [-9, -2, 0, 2, 3], return [0, 4, 4, 9, 81].*/
//
#include <bits/stdc++.h>
using namespace std;
vector<int> _merge( deque<int> left, deque<int> right);

vector<int> square_sort(vector<int> lst)
{
    deque<int> negs, pos;
    for (int i = 0; i < lst.size(); i++)
    {
        if (lst[i] >= 0) pos.push_back(lst[i]*lst[i]);
        else negs.push_front(lst[i]*lst[i]);
    }

    return _merge(negs, pos);
}

vector<int> _merge( deque<int> left, deque<int> right)
{
    vector<int> result;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            result.push_back(left[i]);
            i++;
        }
        else if (left[i] > right[j]) {
            result.push_back(right[i]);
            j++;
        }
        else
        {
            result.push_back(left[i]);
            result.push_back(right[j]);
            i++;
            j++;
        }
    }

    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }

    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }

    return result;
}
int main(void)
{
    vector<int> nums{-9, -2, 0, 2, 3};
    vector<int> result = square_sort(nums);

    for (int x : result)
        cout << x << ", ";

}