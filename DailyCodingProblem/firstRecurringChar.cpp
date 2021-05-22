//
// Created by chris on 5/9/2021.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {

        map<char,int> charmap;
        char result = ' ';
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            charmap[c]++;
            if (charmap[c] > 1)
                return c;
        }

        return result;
    }
};

int main()
{
    string s1 = "abbcdef";
    string s2 = "abcdefg";
    Solution sol;
    cout << sol.firstUniqChar(s1) << endl;
    cout << sol.firstUniqChar(s2) << endl;
    return 0;
}