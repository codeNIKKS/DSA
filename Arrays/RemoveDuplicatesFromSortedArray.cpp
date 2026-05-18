#include <bits/stdc++.h>
using namespace std;

// PROBLEM:
// Remove Duplicates from Sorted Array



// BRUTE FORCE APPROACH
// Use a set to store only unique elements.
// Then place all unique elements back into the array.
//
// TC: O(n log n)
// SC: O(n)



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.empty()) return 0;

        // Set stores unique elements only
        set<int> st;

        // Insert all array elements into set
        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        // Copy unique elements back to original array
        int index = 0;

        for(auto it : st) {
            nums[index] = it;
            index++;
        }

        // Return number of unique elements
        return st.size();
    }
};


// OPTIMAL APPROACH
// Since the array is sorted,
// duplicates will always be adjacent.
//
// Use two pointers:
// i -> points to last unique element
// j -> traverses the array
//
// Whenever a new unique element is found,
// place it at the next position of i.
//
// TC: O(n)
// SC: O(1)



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // Edge case
        if(nums.empty()) return 0;

        int n = nums.size();

        // Pointer for unique elements
        int i = 0;

        // Traverse array
        for(int j = 1; j < n; j++) {

            // New unique element found
            if(nums[j] != nums[i]) {

                i++;

                nums[i] = nums[j];
            }
        }

        // Number of unique elements
        return i + 1;
    }
};