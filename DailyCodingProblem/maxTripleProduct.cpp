/*
 * This problem was asked by Facebook.

Given a list of integers, return the largest product that can be made by multiplying any three integers.

For example, if the list is [-10, -10, 5, 2], we should return 500, since that's -10 * -10 * 5.

You can assume the list has at least three integers.

Solution
If all the integers were positive, then we would simply need to take the three largest numbers of the array. Then, we can just sort it and return the last three elements.

However, we need to account for negative numbers in the array. If the largest product that can be made includes a negative number, we would need to have two so as to cancel out the negatives. So, we can take the larger of:

The three largest numbers
The two smallest (most negative) numbers, and the largest number
def maximum_product_of_three(lst):
    lst.sort()
    third_largest, second_largest, first_largest = lst[-3], lst[-2], lst[-1]
    first_smallest, second_smallest = lst[0], lst[1]
    return max(third_largest * second_largest * first_largest,
    first_largest * first_smallest * second_smallest)
This runs in O(N log N) time since we have to sort the input array.

We could also do this in O(N) time by using select or looking for the largest elements manually.

from math import inf

def maximum_product_of_three(lst):
    max1, max2, max3, min1, min2 = -inf, -inf, -inf, inf, inf

    for x in lst:
        if x > max1:
            max3 = max2
            max2 = max1
            max1 = x
        elif x > max2:
            max3 = max2
            max2 = x
        elif x > max3:
            max3 = x

        if x < min1:
            min2 = min1
            min1 = x
        elif x < min2:
            min2 = x

    return max(max1 * max2 * max3, max1 * min1 * min2)
 */

// A C++ program to find a maximum product of a
// triplet in array of integers
#include <bits/stdc++.h>
using namespace std;

/* Function to find a maximum product of a triplet
in array of integers of size n */
int maxProduct(vector<int> arr)
{
    int n = arr.size();
	// if size is less than 3, no triplet exists
	if (n < 3)
		return -1;

	// will contain max product
	int max_product = INT_MIN;

	for (int i = 0; i < n - 2; i++)
		for (int j = i + 1; j < n - 1; j++)
			for (int k = j + 1; k < n; k++)
				max_product = max(max_product,
						arr[i] * arr[j] * arr[k]);

	return max_product;
}

// A C++ program to find a maximum product of a triplet
// in array of integers
/*
 * Approach 2: O(n) Time, O(n) Space

Construct four auxiliary arrays leftMax[], rightMax[], leftMin[] and rightMin[] of same size as input array.
Fill leftMax[], rightMax[], leftMin[] and rightMin[] in below manner.
leftMax[i] will contain maximum element on left of arr[i] excluding arr[i]. For index 0, left will contain -1.
leftMin[i] will contain minimum element on left of arr[i] excluding arr[i]. For index 0, left will contain -1.
rightMax[i] will contain maximum element on right of arr[i] excluding arr[i]. For index n-1, right will contain -1.
rightMin[i] will contain minimum element on right of arr[i] excluding arr[i]. For index n-1, right will contain -1.
For all array indexes i except first and last index, compute maximum of arr[i]*x*y where x can be leftMax[i] or leftMin[i] and y can be rightMax[i] or rightMin[i].
Return the maximum from step 3.
 */
/* Function to find a maximum product of a triplet
in array of integers of size n */
int maxProduct2(vector<int> arr)
{
    int n = arr.size();
    // if size is less than 3, no triplet exists
    if (n < 3)
        return -1;

    // Construct four auxiliary vectors
    // of size n and initailize them by -1
    vector<int> leftMin(n, -1);
    vector<int> rightMin(n, -1);
    vector<int> leftMax(n, -1);
    vector<int> rightMax(n, -1);

    // will contain max product
    int max_product = INT_MIN;

    // to store maximum element on left of array
    int max_sum = arr[0];

    // to store minimum element on left of array
    int min_sum = arr[0];

    // leftMax[i] will contain max element
    // on left of arr[i] excluding arr[i].
    // leftMin[i] will contain min element
    // on left of arr[i] excluding arr[i].
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max_sum;
        if (arr[i] > max_sum)
            max_sum = arr[i];

        leftMin[i] = min_sum;
        if (arr[i] < min_sum)
            min_sum = arr[i];
    }

    // reset max_sum to store maximum element on
    // right of array
    max_sum = arr[n - 1];

    // reset min_sum to store minimum element on
    // right of array
    min_sum = arr[n - 1];

    // rightMax[i] will contain max element
    // on right of arr[i] excluding arr[i].
    // rightMin[i] will contain min element
    // on right of arr[i] excluding arr[i].
    for (int j = n - 2; j >= 0; j--)
    {
        rightMax[j] = max_sum;
        if (arr[j] > max_sum)
            max_sum = arr[j];

        rightMin[j] = min_sum;
        if (arr[j] < min_sum)
            min_sum = arr[j];
    }

    // For all array indexes i except first and
    // last, compute maximum of arr[i]*x*y where
    // x can be leftMax[i] or leftMin[i] and
    // y can be rightMax[i] or rightMin[i].
    for (int i = 1; i < n - 1; i++)
    {
        int max1 = max(arr[i] * leftMax[i] * rightMax[i],
                       arr[i] * leftMin[i] * rightMin[i]);

        int max2 = max(arr[i] * leftMax[i] * rightMin[i],
                       arr[i] * leftMin[i] * rightMax[i]);

        max_product = max(max_product, max(max1, max2));
    }

    return max_product;
}
/*
 *
 * Approach 3: O(nlogn) Time, O(1) Space

Sort the array using some efficient in-place sorting algorithm in ascending order.
Return the maximum of product of last three elements of the array and product of first two elements and last element.
 */
/* Function to find a maximum product of a triplet
   in array of integers of size n */
int maxProduct3(vector<int> arr)
{
    int n = arr.size();
    // if size is less than 3, no triplet exists
    if (n < 3)
        return -1;

    // Sort the array in ascending order
    sort(arr.begin(), arr.begin() + n);

    // Return the maximum of product of last three
    // elements and product of first two elements
    // and last element
    return max(arr[0] * arr[1] * arr[n - 1],
               arr[n - 1] * arr[n - 2] * arr[n - 3]);
}
/*
 * Approach 4: O(n) Time, O(1) Space

Scan the array and compute Maximum, second maximum and third maximum element present in the array.
Scan the array and compute Minimum and second minimum element present in the array.
Return the maximum of product of Maximum, second maximum and third maximum and product of Minimum, second minimum and Maximum element.
Note – Step 1 and Step 2 can be done in single traversal of the array.
 */

/* Function to find a maximum product of a triplet
   in array of integers of size n */
int maxProduct4(vector<int> arr)
{
    int n = arr.size();
    // if size is less than 3, no triplet exists
    if (n < 3)
        return -1;

    // Initialize Maximum, second maximum and third
    // maximum element
    int maxA = INT_MIN, maxB = INT_MIN, maxC = INT_MIN;

    // Initialize Minimum and second mimimum element
    int minA = INT_MAX, minB = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        // Update Maximum, second maximum and third
        // maximum element
        if (arr[i] > maxA)
        {
            maxC = maxB;
            maxB = maxA;
            maxA = arr[i];
        }

            // Update second maximum and third maximum element
        else if (arr[i] > maxB)
        {
            maxC = maxB;
            maxB = arr[i];
        }

            // Update third maximum element
        else if (arr[i] > maxC)
            maxC = arr[i];

        // Update Minimum and second mimimum element
        if (arr[i] < minA)
        {
            minB = minA;
            minA = arr[i];
        }

            // Update second mimimum element
        else if(arr[i] < minB)
            minB = arr[i];
    }

    return max(minA * minB * maxA,
               maxA * maxB * maxC);
}
// Driver program to test above functions
int main()
{
    vector<int> arr1 = { 1, 4, 3, -6, -7, 0 };
    vector<int> arr2 = { 10, 3, 5, 6, 20 };
    vector<int> arr3 = { -10, -3, 5, 6, -20 };
    vector<int> arr4 = { 1, -4, 3, -6, 7, 0 };
    vector<vector<int>> all_arrs = {arr1, arr2, arr3, arr4};
    int max = INT_MIN;
    for (vector<int> arr : all_arrs)
    {
        max = maxProduct(arr);
        if (max == -1)
            cout << "No Triplet Exists" << endl;
        else
            cout << "Maximum product is " << max << endl;

        max = maxProduct2(arr);
        if (max == -1)
            cout << "No Triplet Exists" << endl;
        else
            cout << "Maximum product is " << max << endl;

        max = maxProduct3(arr);
        if (max == -1)
            cout << "No Triplet Exists" << endl;
        else
            cout << "Maximum product is " << max << endl;

        max = maxProduct4(arr);
        if (max == -1)
            cout << "No Triplet Exists" << endl;
        else
            cout << "Maximum product is " << max << endl;

        cout << "---------------------------------------" << endl; 
    }
	return 0;
}
