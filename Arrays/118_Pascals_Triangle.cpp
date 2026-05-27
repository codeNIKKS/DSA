/*
    LeetCode 118 - Pascal's Triangle
    Brute Force Approach (Generate Each Element Individually)

    Intuition:
    Every element in Pascal's Triangle can be represented using nCr.
    For each row, we calculate every element separately using the
    combination formula.

    Formula:
    nCr = n! / (r! * (n-r)!)

    Approach:
    1. Traverse each row from 0 to numRows-1.
    2. For every column in that row:
       - Calculate the value using nCr(row, col).
    3. Store the generated row into the answer vector.

    Time Complexity:
    O(n^3)
    -> n rows
    -> n columns
    -> each nCr calculation takes O(n)

    Space Complexity:
    O(1) auxiliary space
    (excluding the output array)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int nCr(int n, int r) {

        int ans = 1;

        for(int i = 0; i < r; i++) {

            ans = ans * (n - i);
            ans = ans / (i + 1);
        }

        return ans;
    }

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        for(int row = 0; row < numRows; row++) {

            vector<int> temp;

            for(int col = 0; col <= row; col++) {

                temp.push_back(nCr(row, col));
            }

            ans.push_back(temp);
        }

        return ans;
    }
};


/*
    LeetCode 118 - Pascal's Triangle
    Optimal Approach (Using Previous Element Formula)

    Intuition:
    Instead of calculating every element separately using factorials,
    we can generate the next element from the previous element.

    Observation:
    If current element is nCr,
    then next element can be generated using:

    next = current * (n - r) / (r + 1)

    This avoids repeated factorial calculations and generates
    every row efficiently.

    Approach:
    1. Traverse each row from 1 to numRows.
    2. Start every row with 1.
    3. Generate remaining elements using the previous element.
    4. Store each generated row in the answer vector.

    Time Complexity:
    O(n^2)

    Space Complexity:
    O(1) auxiliary space
    (excluding the output array)
*/

class Solution {
public:

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        for(int row = 1; row <= numRows; row++) {

            vector<int> temp;

            int el = 1;
            temp.push_back(el);

            for(int col = 1; col < row; col++) {

                el = el * (row - col) / col;

                temp.push_back(el);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};