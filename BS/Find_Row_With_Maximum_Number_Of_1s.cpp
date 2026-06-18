/*
-------------------------------------------------------
Problem: Find Row With Maximum Number Of 1s
Topic: Binary Search
Approach: Brute Force (Count 1s in Every Row)
-------------------------------------------------------

Intuition:
- Traverse every row of the matrix.
- Count the number of 1s present in each row.
- Keep track of the row having the maximum count of 1s.
- If multiple rows have the same count, keep the smaller index.
- If no 1 exists in the matrix, return -1.

Approach:
1. Initialize:
   - max1s = 0
   - index = -1
2. Traverse each row.
3. Count the number of 1s in that row.
4. If count > max1s:
      - update max1s
      - update index
5. Return index.

Time Complexity: O(R * C)
Space Complexity: O(1)

-------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &mat) {
        int r = mat.size();
        int c = mat[0].size();

        int max1s = 0;
        int index = -1;

        for(int i = 0; i < r; i++) {
            int cnt = 0;

            for(int j = 0; j < c; j++) {
                if(mat[i][j] == 1) {
                    cnt++;
                }
            }

            if(cnt > max1s) {
                max1s = cnt;
                index = i;
            }
        }

        return index;
    }
};


/*
-------------------------------------------------------
Problem: Find Row With Maximum Number Of 1s
Topic: Binary Search
Approach: Better (Binary Search on Every Row)
-------------------------------------------------------

Intuition:
- Each row is sorted in non-decreasing order.
- Therefore, all 0s appear before all 1s.
- For every row, find the first occurrence of 1 using
  Binary Search (Lower Bound).
- If the first 1 occurs at index 'idx', then:
      Number of 1s = m - idx
- Keep track of the row having the maximum count of 1s.

Approach:
1. Traverse every row of the matrix.
2. Use Binary Search to find the first occurrence of 1.
3. Calculate:
      countOnes = m - firstOneIndex
4. If countOnes > max1s:
      - update max1s
      - update row index
5. Return the row index.

Time Complexity: O(R * log C)
Space Complexity: O(1)

-------------------------------------------------------
*/

class Solution {
public:
    int lowerBound(vector<int>& arr, int n, int x) {
        int low = 0;
        int high = n - 1;
        int ans = n;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int rowWithMax1s(vector<vector<int>> &mat) {
        int r = mat.size();
        int c = mat[0].size();

        int max1s = 0;
        int index = -1;

        for(int i = 0; i < r; i++) {
            int ones = c - lowerBound(mat[i], c, 1);

            if(ones > max1s) {
                max1s = ones;
                index = i;
            }
        }

        return index;
    }
};


/*
-------------------------------------------------------
Problem: Find Row With Maximum Number Of 1s
Topic: Binary Search
Approach: Optimal (Top-Right Corner Traversal)
-------------------------------------------------------

Intuition:
- Since each row is sorted, all 0s appear before all 1s.
- Start from the top-right corner of the matrix.
- If the current element is 1:
    - This row has at least as many 1s as any row below it
      for the current column position.
    - Update the answer and move left to look for more 1s.
- If the current element is 0:
    - All elements to its left are also 0.
    - Move down to the next row.
- Each move either decreases the column index or increases
  the row index.
- Therefore, every row and column is visited at most once.

Approach:
1. Start from the top-right corner:
      row = 0, col = m - 1
2. While row < n and col >= 0:
      - If mat[row][col] == 1:
            answer = row
            col--
      - Else:
            row++
3. Return the answer.

Time Complexity: O(R + C)
Space Complexity: O(1)

-------------------------------------------------------
*/

class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &mat) {
        int r = mat.size();
        int c = mat[0].size();

        int row = 0;
        int col = c - 1;
        int index = -1;

        while(row < r && col >= 0) {
            if(mat[row][col] == 1) {
                index = row;
                col--;
            }
            else {
                row++;
            }
        }

        return index;
    }
};


