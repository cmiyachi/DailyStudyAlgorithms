//
// Created by chris on 2/28/2021.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int k = 0;
        while (target > 0)
            target -= ++k;
        return target % 2 == 0 ? k : k + 1 + k%2;
    }
};

int main(void)
{
    Solution sol;
    cout << sol.reachNumber(7);
    return 0;
}
/*
 * First note that it is not that important whether N is positive or negative, since the number line is symmetric about zero. In other words, if we want to find out the optimal path to a negative target, we can just solve for the positive target and reverse all the jumps at the end.

For a positive target, if we are lucky, we can keep jumping to the right until we land on N. More mathematically, this would happen if for some number k, it is true that 1 + 2 + ... + k = N. This is the case for 3 and 10, for example. Any such solution would have to be optimal, since we never go backwards.

It may happen, however, that instead of exactly landing on N, we go a few places beyond. Here we can divide our situation into two cases, depending on whether the difference between 1 + 2 + ... + k and N is even or odd.

If the difference is even, there must be some integer in our path whose sign we can flip to get to the correct total. More specifically, there exists i < k such that our difference equals 2 * i, and if we move to the left instead of the right from i, we will obtain the correct path. For example, suppose N = 4, and our total is 1 + 2 + 3 = 6. Then, instead of jumping right at index 1, we should jump left, giving us the path 0 -> -1 -> 1 -> 4.

If the difference is odd, we can simply add numbers to the list until the total becomes even. At most this will take two new numbers, since we only need to ensure an odd integer is added. Finally, we can apply the strategy above on the longer list. For example, if N = 7, we must jump ahead to 1 + 2 + 3 + 4 + 5 = 15, and reverse the jump from i = 4.

def make_path(nums, is_negative):

 The sum of 1 + 2 + ... + k evaluates to k * (k + 1) // 2, so the length of our path will be roughly the square root of N. We must run our while loop for this many iterations, and store a solution path of this length, so the time and space complexity will be O(√N).
 */