/*
=========================================================
1901. Find Peak Element II
LeetCode Hard
=========================================================

Problem Link:
https://leetcode.com/problems/find-a-peak-element-ii/

---------------------------------------------------------
Intuition
---------------------------------------------------------
A peak element in a 2D grid is an element that is strictly
greater than its left, right, top, and bottom neighbors.

The most straightforward approach is to check every cell
in the matrix and verify whether it satisfies the peak
condition.

As soon as we find a valid peak, we return its position.

---------------------------------------------------------
Approach
---------------------------------------------------------
1. Traverse every cell of the matrix.
2. For each cell:
   - Check left neighbor.
   - Check right neighbor.
   - Check top neighbor.
   - Check bottom neighbor.
3. Boundary cells treat outside values as -1.
4. If all four conditions are satisfied, return {row,col}.
5. If no peak is found, return {-1,-1}.

---------------------------------------------------------
Time Complexity
---------------------------------------------------------
O(n * m)

n = number of rows
m = number of columns

---------------------------------------------------------
Space Complexity
---------------------------------------------------------
O(1)

---------------------------------------------------------
Mistake / Learning
---------------------------------------------------------
- Direct simulation approach.
- Useful for understanding the peak condition.
- Does not utilize the special structure of the problem.
- Fails the expected optimal complexity O(n log m).
=========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int r = mat.size();
        int c = mat[0].size();

        for(int i = 0; i < r; i++) {

            for(int j = 0; j < c; j++) {

                bool left = (j == 0) || (mat[i][j] > mat[i][j - 1]);
                bool right = (j == c - 1) || (mat[i][j] > mat[i][j + 1]);
                bool top = (i == 0) || (mat[i][j] > mat[i - 1][j]);
                bool bottom = (i == r - 1) || (mat[i][j] > mat[i + 1][j]);

                if(left && right && top && bottom) {
                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }
};


/*
=========================================================
1901. Find Peak Element II
LeetCode Hard
=========================================================

Problem Link:
https://leetcode.com/problems/find-a-peak-element-ii/

---------------------------------------------------------
Intuition
---------------------------------------------------------
Instead of checking every cell, we can use Binary Search
on columns.

For a selected middle column:
- Find the maximum element in that column.
- Since it is the maximum in its column, it is already
  greater than its top and bottom neighbors.
- We only need to compare it with its left and right
  neighbors.

Cases:
1. Current element > left and right
   -> Peak found.

2. Left neighbor > current element
   -> A peak must exist on the left side.

3. Right neighbor > current element
   -> A peak must exist on the right side.

Thus we can eliminate half of the columns in every step.

---------------------------------------------------------
Approach
---------------------------------------------------------
1. Apply Binary Search on columns.
2. For each middle column:
   - Find the row containing the maximum element.
3. Compare the maximum element with its left and right
   neighbors.
4. If it is greater than both:
      return its coordinates.
5. Otherwise move towards the larger neighbor.
6. Continue until a peak is found.

---------------------------------------------------------
Time Complexity
---------------------------------------------------------
O(n * log m)

n = number of rows
m = number of columns

Finding maximum element in a column -> O(n)
Binary Search on columns -> O(log m)

---------------------------------------------------------
Space Complexity
---------------------------------------------------------
O(1)

---------------------------------------------------------
Mistake / Learning
---------------------------------------------------------
- Key observation:
  Maximum element of a column automatically satisfies
  the vertical (top & bottom) peak condition.
- Only left and right comparisons are needed.
- Classic Binary Search on 2D Matrix pattern.
=========================================================
*/

class Solution {
public:

    int maxelem(vector<vector<int>>& mat, int r, int c, int col) {

        int maxvalue = -1;
        int index = -1;

        for(int i = 0; i < r; i++) {

            if(mat[i][col] > maxvalue) {
                maxvalue = mat[i][col];
                index = i;
            }
        }

        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int r = mat.size();
        int c = mat[0].size();

        int low = 0;
        int high = c - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            int row = maxelem(mat, r, c, mid);

            int left = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
            int right = (mid + 1 < c) ? mat[row][mid + 1] : -1;

            if(mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            }
            else if(left > mat[row][mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};