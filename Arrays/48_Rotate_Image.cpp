/*
========================================================
Brute Force Approach : Rotate Matrix by 90 Degrees
========================================================

Problem:
Given an N x N matrix, rotate the matrix by 90 degrees
clockwise.

Approach:
1. Create a temporary matrix of same size.
2. Copy all elements from original matrix into temp.
3. Place each element at its rotated position using:
   
   matrix[j][n - 1 - i] = temp[i][j]

4. This forms a 90 degree clockwise rotated matrix.

Example:
Input:
1 2 3
4 5 6
7 8 9

Output:
7 4 1
8 5 2
9 6 3

Time Complexity  : O(N^2)
Space Complexity : O(N^2)

========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Temporary matrix
        vector<vector<int>> temp(n, vector<int>(n));

        // Copy original matrix into temp
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                temp[i][j] = matrix[i][j];
            }
        }

        // Rotate matrix by 90 degrees clockwise
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                matrix[j][n - 1 - i] = temp[i][j];
            }
        }
    }
};


/*
========================================================
Optimal Approach : Rotate Matrix by 90 Degrees
========================================================

Problem:
Given an N x N matrix, rotate the matrix by
90 degrees clockwise in-place.

Optimal Intuition:
A 90 degree clockwise rotation can be achieved in 2 steps:

1. Transpose the matrix
   -> Convert rows into columns

2. Reverse every row
   -> This gives the final rotated matrix

Example:

Original Matrix:
1 2 3
4 5 6
7 8 9

After Transpose:
1 4 7
2 5 8
3 6 9

After Reversing Rows:
7 4 1
8 5 2
9 6 3

Important Learnings:
1. While transposing,
   inner loop starts from:
   
   j = i + 1

   This avoids swapping elements again.

2. Reversing a row inside matrix:
   
   reverse(matrix[i].begin(), matrix[i].end());

Time Complexity  : O(N^2)
Space Complexity : O(1)

========================================================
*/

class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Step 1: Transpose matrix
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse every row
        for(int i = 0; i < n; i++) {

            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};