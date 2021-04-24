#include <bits/stdc++.h>
using namespace std;
/*
 * You are given a histogram consisting of rectangles of different heights.
 * These heights are represented in an input list, such that [1, 3, 2, 5] corresponds to the following diagram:

      x
      x
  x   x
  x x x
x x x x
Determine the area of the largest rectangle that can be formed only from the bars of the histogram.
 For the diagram above, for example, this would be six, representing the 2 x 3 area at the bottom right.
 */
// On3 - limited by lowest rectangle between two bars
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        size_t max_area = 0;
        for (size_t i = 0; i < heights.size(); i++) {
            for (size_t j = i; j < heights.size(); j++) {
                int min_height = INT_MAX;
                for (size_t k = i; k <= j; k++) {
                    min_height = min(min_height, heights[k]);
                }
                max_area = max(max_area, min_height * (j - i + 1));
            }
        }
        return max_area;
    }
};
// On2 - use previous pairs min height
class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        size_t max_area = 0;
        for (size_t i = 0; i < heights.size(); i++) {
            int min_height = INT_MAX;
            for (size_t j = i; j < heights.size(); j++) {
                min_height = min(min_height, heights[j]);
                max_area = max(max_area, min_height * (j - i + 1));
            }
        }
        return max_area;
    }
};
/*
 * The widest possible rectangle with height equal to the height of the shortest bar.

The largest rectangle confined to the left of the shortest bar(subproblem).

The largest rectangle confined to the right of the shortest bar(subproblem).
 */
class Solution3 {
public:
    int calculateArea(vector<int>& heights, int start, int end) {
        if (start > end) {
            return 0;
        }
        int min_index = start;
        for (int i = start; i <= end; i++) {
            if (heights[min_index] > heights[i]) {
                min_index = i;
            }
        }
        return max({heights[min_index] * (end - start + 1),
                    calculateArea(heights, start, min_index - 1),
                    calculateArea(heights, min_index + 1, end)});
    }

    int largestRectangleArea(vector<int>& heights) {
        return calculateArea(heights, 0, heights.size() - 1);
    }
};
class Solution4 {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        stk.push(-1);
        int max_area = 0;
        for (size_t i = 0; i < heights.size(); i++) {
            while (stk.top() != -1 and heights[stk.top()] >= heights[i]) {
                int current_height = heights[stk.top()];
                stk.pop();
                int current_width = i - stk.top() - 1;
                max_area = max(max_area, current_height * current_width);
            }
            stk.push(i);
        }
        while (stk.top() != -1) {
            int current_height = heights[stk.top()];
            stk.pop();
            int current_width = heights.size() - stk.top() - 1;
            max_area = max(max_area, current_height * current_width);
        }
        return max_area;
    }
};

int main(void)
{
    vector<int> heights = {2,1,5,6,2,3};
    Solution4 sol;

    cout << sol.largestRectangleArea(heights);

    return 0;
}