/*
========================================================
🔹 Spiral Matrix Traversal (Clockwise)
========================================================

Problem:
Given an M x N matrix, return all elements
in spiral order.

--------------------------------------------------------
Intuition:
We traverse the matrix layer by layer using
4 boundaries:

1. top    -> starting row
2. bottom -> ending row
3. left   -> starting column
4. right  -> ending column

Traversal Order:
1. Left  → Right
2. Top   → Bottom
3. Right → Left
4. Bottom → Top

After completing one direction,
we shrink the corresponding boundary.

Important:
Before traversing bottom row and left column,
we check boundaries again to avoid duplicate
elements in rectangular matrices.

--------------------------------------------------------
Time Complexity:
O(m * n)

Space Complexity:
O(1) extra space
(excluding output array)

--------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while(left <= right && top <= bottom) {

            // Traverse Left -> Right
            for(int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // Traverse Top -> Bottom
            for(int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Traverse Right -> Left
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Traverse Bottom -> Top
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};