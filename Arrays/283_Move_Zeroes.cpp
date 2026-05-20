#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------- Brute Force Approach ----------------------------------

Intuition:
- Store all non-zero elements in a temporary array.
- Fill remaining positions with 0.
- Copy elements back to original array.

Time Complexity: O(N)
Space Complexity: O(N)

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();

        vector<int> temp;

        // Store all non-zero elements
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                temp.push_back(nums[i]);
            }
        }

        // Fill remaining positions with 0
        while(temp.size() < n) {
            temp.push_back(0);
        }

        // Copy back to original array
        for(int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
    }
};


/*
---------------------------------- Better Approach ----------------------------------

Intuition:
- Whenever a zero is found, shift all elements to the left.
- Place 0 at the end of the array.
- Do not increment index after shifting because a new element
  comes at the same position.

Time Complexity: O(N²)
Space Complexity: O(1)

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();

        int i = 0;

        while(i < n) {

            // If current element is zero
            if(nums[i] == 0) {

                // Shift elements left
                for(int j = i; j < n - 1; j++) {
                    nums[j] = nums[j + 1];
                }

                // Put zero at the end
                nums[n - 1] = 0;
            }
            else {
                i++;
            }
        }
    }
};


/*
---------------------------------- Optimal Approach ----------------------------------

Intuition:
- Use one pointer 'j' to track the position where the next
  non-zero element should be placed.
- Traverse the array using pointer 'i'.
- Whenever a non-zero element is found, swap it with nums[j]
  and increment j.
- This automatically pushes all zeroes to the end while
  maintaining the relative order of non-zero elements.

Time Complexity: O(N)
Space Complexity: O(1)

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();

        int j = 0;

        for(int i = 0; i < n; i++) {

            // If non-zero element found
            if(nums[i] != 0) {

                swap(nums[i], nums[j]);

                j++;
            }
        }
    }
};