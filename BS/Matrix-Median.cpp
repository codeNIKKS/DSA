/*
Problem: Matrix Median (GFG)

Intuition:
The matrix is row-wise sorted, but not globally sorted.
A straightforward approach is to store all elements in a single array,
sort it, and return the middle element.

Approach:
1. Traverse the matrix and push every element into a 1D vector.
2. Sort the vector.
3. Return the element at index (n*m)/2.

Time Complexity: O((N*M) * log(N*M))
Space Complexity: O(N*M)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMedian(vector<vector<int>> &matrix) {
        vector<int> arr;

        int r = matrix.size();
        int c = matrix[0].size();

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                arr.push_back(matrix[i][j]);
            }
        }

        sort(arr.begin(), arr.end());

        return arr[(r * c) / 2];
    }
};


/*
Problem: Matrix Median (GFG)

Approach:
We cannot directly apply binary search on indices because the matrix is
only row-wise sorted, not completely sorted.

Instead, perform Binary Search on the Answer.

1. The median lies between:
   - Minimum element among all first column elements.
   - Maximum element among all last column elements.

2. For every candidate value 'mid':
   - Count how many elements in the matrix are <= mid.
   - Since each row is sorted, use Upper Bound in each row.

3. If count <= required position:
      median is larger, move right.
   Else:
      median can be smaller, move left.

4. The first value having more than (N*M)/2 elements less than or equal
   to it is the median.

Time Complexity: O(R * log(C) * log(MaxVal - MinVal))
Space Complexity: O(1)
*/

class Solution {
public:
    int cntSmallEquals(vector<vector<int>>& mat, int r, int c, int x) {
        int cnt = 0;

        for(int i = 0; i < r; i++) {
            cnt += ub(mat[i], c, x);
        }

        return cnt;
    }

    int ub(vector<int>& arr, int c, int x) {
        int low = 0;
        int high = c - 1;
        int ans = c;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(arr[mid] > x) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int findMedian(vector<vector<int>> &matrix) {
        int low = INT_MAX;
        int high = INT_MIN;

        int r = matrix.size();
        int c = matrix[0].size();

        for(int i = 0; i < r; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][c - 1]);
        }

        int req = (r * c) / 2;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int smallEquals = cntSmallEquals(matrix, r, c, mid);

            if(smallEquals <= req) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
    }
};