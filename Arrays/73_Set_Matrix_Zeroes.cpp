/*
    LeetCode 73 - Set Matrix Zeroes
    Brute Force Approach

    Intuition:
    - Whenever we encounter a 0 in the matrix,
      we mark its entire row and column with -1.
    - We use -1 as a temporary marker so that
      newly marked cells do not affect traversal.
    - After marking is complete, convert all -1 to 0.

    Approach:
    1. Traverse the matrix.
    2. If matrix[i][j] == 0:
        - Mark entire row with -1
        - Mark entire column with -1
    3. Traverse again and convert all -1 to 0.

    Time Complexity:
    - O((m * n) * (m + n))

    Space Complexity:
    - O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    void markRow(vector<vector<int>>& matrix, int i, int n) {

        for(int j = 0; j < n; j++) {

            if(matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }

    void markColumn(vector<vector<int>>& matrix, int j, int m) {

        for(int i = 0; i < m; i++) {

            if(matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        // Mark rows and columns
        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(matrix[i][j] == 0) {

                    markRow(matrix, i, n);
                    markColumn(matrix, j, m);
                }
            }
        }

        // Convert -1 to 0
        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

/*
    LeetCode 73 - Set Matrix Zeroes
    Better Approach

    Intuition:
    - Store the rows and columns that contain 0 separately.
    - Use two extra arrays:
        row[]    -> marks rows to be converted into 0
        column[] -> marks columns to be converted into 0

    Approach:
    1. Traverse the matrix.
    2. If matrix[i][j] == 0:
        - row[i] = 1
        - column[j] = 1
    3. Traverse row array:
        - If row[i] == 1, make entire row 0.
    4. Traverse column array:
        - If column[j] == 1, make entire column 0.

    Time Complexity:
    - O(m * n)

    Space Complexity:
    - O(m + n)
*/

class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row(m, 0);
        vector<int> column(n, 0);

        // Store rows and columns containing 0
        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(matrix[i][j] == 0) {

                    row[i] = 1;
                    column[j] = 1;
                }
            }
        }

        // Make marked rows zero
        for(int i = 0; i < m; i++) {

            if(row[i] == 1) {

                for(int j = 0; j < n; j++) {

                    matrix[i][j] = 0;
                }
            }
        }

        // Make marked columns zero
        for(int j = 0; j < n; j++) {

            if(column[j] == 1) {

                for(int i = 0; i < m; i++) {

                    matrix[i][j] = 0;
                }
            }
        }
    }
};


/*
    LeetCode 73 - Set Matrix Zeroes
    Optimal Approach

    Intuition:
    - Instead of using extra row[] and column[] arrays,
      use the first row and first column of the matrix
      itself as marker arrays.

    - matrix[i][0] -> marks whether row i should become 0
    - matrix[0][j] -> marks whether column j should become 0

    - Since matrix[0][0] belongs to both first row
      and first column, use an extra variable col0
      to separately track the first column.

    Approach:
    1. Traverse the matrix and store markers:
        - If matrix[i][j] == 0:
            matrix[i][0] = 0
            matrix[0][j] = 0

    2. Traverse from (1,1):
        - If row marker OR column marker is 0,
          make the cell 0.

    3. Handle first row separately using matrix[0][0].

    4. Handle first column separately using col0.

    Time Complexity:
    - O(m * n)

    Space Complexity:
    - O(1)
*/

class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int col0 = 1;

        // Step 1: Store markers
        for(int i = 0; i < m; i++) {

            if(matrix[i][0] == 0) {
                col0 = 0;
            }

            for(int j = 1; j < n; j++) {

                if(matrix[i][j] == 0) {

                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 2: Mark remaining cells
        for(int i = 1; i < m; i++) {

            for(int j = 1; j < n; j++) {

                if(matrix[i][0] == 0 || matrix[0][j] == 0) {

                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Handle first row
        if(matrix[0][0] == 0) {

            for(int j = 0; j < n; j++) {

                matrix[0][j] = 0;
            }
        }

        // Step 4: Handle first column
        if(col0 == 0) {

            for(int i = 0; i < m; i++) {

                matrix[i][0] = 0;
            }
        }
    }
};