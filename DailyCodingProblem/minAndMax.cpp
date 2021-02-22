//
// Created by chris on 2/21/2021.
//
#include <bits/stdc++.h>
using namespace std;

pair<int, int> compareElements(int x, int y)
{
    pair<int, int> res{x,y};
    if (x > y) {
        res.first = y;
        res.second = x;
    }

    return res;
}
pair<int, int>  minAndMax(vector<int> arr)
{
    int min_element = arr[0];
    int max_element = arr[0];
    //# Make the list odd so we can pair up the remaining elements neatly.
    if (arr.size() %2 == 0)
        arr.push_back(arr[arr.size()-1]);

    for (int i = 0; i < arr.size(); i=i+2)
    {
        pair<int,int> res = compareElements(arr[i], arr[i+1]);
        min_element = min(min_element,res.first);
        max_element = max(max_element, res.second);
    }

    pair<int, int> final{min_element, max_element};
    return final;
}

int main(void)
{
    vector<int> nums{4, 2, 7, 5, -1, 3, 6};

    pair<int, int> res = minAndMax(nums);

    cout << res.first << " " << res.second; 
}