/*
=========================================================
LeetCode 74. Search a 2D Matrix
=========================================================

Problem Link:
https://leetcode.com/problems/search-a-2d-matrix/

Approach: Brute Force (Linear Traversal)
----------------------------------------
- Traverse every element of the matrix.
- If any element equals target, return true.
- If traversal completes without finding target,
  return false.

Time Complexity: O(m * n)
Space Complexity: O(1)

---------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(matrix[i][j] == target)
                    return true;
            }
        }

        return false;
    }
};


/*
=========================================================
LeetCode 74. Search a 2D Matrix
=========================================================

Problem Link:
https://leetcode.com/problems/search-a-2d-matrix/

Approach: Better (Check Row + Binary Search)
--------------------------------------------
- Since each row is sorted, first determine whether
  the target can lie in the current row.
- A target can only be present in a row if:

      matrix[i][0] <= target <= matrix[i][n-1]

- Once such a row is found, perform Binary Search
  on that row.
- If target is found, return true.
- Otherwise return false.

Time Complexity: O(m + log n)
Space Complexity: O(1)

---------------------------------------------------------
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; i++) {

            if(matrix[i][0] <= target &&
               matrix[i][n - 1] >= target) {

                int low = 0;
                int high = n - 1;

                while(low <= high) {

                    int mid = low + (high - low) / 2;

                    if(matrix[i][mid] == target)
                        return true;

                    else if(matrix[i][mid] > target)
                        high = mid - 1;

                    else
                        low = mid + 1;
                }
            }
        }

        return false;
    }
};


/*
=========================================================
LeetCode 74. Search a 2D Matrix
=========================================================

Problem Link:
https://leetcode.com/problems/search-a-2d-matrix/

Approach: Optimal (Binary Search on Virtual 1D Array)
-----------------------------------------------------
- Observe that the matrix is completely sorted:
    * Each row is sorted.
    * First element of a row is greater than the
      last element of the previous row.
- Therefore, the entire matrix can be treated as
  a single sorted 1D array of size (m * n).

- Apply Binary Search on indices [0, m*n - 1].
- Convert the 1D index back to 2D coordinates:

      row = mid / n
      col = mid % n

- Compare matrix[row][col] with target and
  update the search space accordingly.

Time Complexity: O(log(m * n))
Space Complexity: O(1)

---------------------------------------------------------
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = (m * n) - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            int row = mid / n;
            int col = mid % n;

            if(matrix[row][col] == target)
                return true;

            else if(matrix[row][col] > target)
                high = mid - 1;

            else
                low = mid + 1;
        }

        return false;
    }
};

/*
---------------------------------------------------------
Mistake / Learning
---------------------------------------------------------
1. Treating the matrix as a virtual 1D sorted array
   eliminates the need to search row-by-row.

2. Mapping Formula:
      row = mid / n
      col = mid % n

3. Always calculate mid as:
      low + (high - low) / 2
   to avoid integer overflow.

4. This is the most optimal solution because a
   single Binary Search is performed over all
   m*n elements.
---------------------------------------------------------
*/