/*
    LeetCode 240. Search a 2D Matrix II

    Approach:
    - Start from the top-right corner of the matrix.
    - If current element equals target, return true.
    - If current element is greater than target, move left.
    - If current element is smaller than target, move down.
    - At every step, one row or one column is eliminated.

    Time Complexity: O(m + n)
    Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n - 1;

        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] > target) {
                col--;
            }
            else {
                row++;
            }
        }

        return false;
    }
};