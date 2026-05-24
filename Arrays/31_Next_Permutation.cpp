/*
    Problem: 31. Next Permutation
    Platform: LeetCode
    Approach: Brute Force (Recursion + Backtracking)

    Intuition:
    Generate all possible permutations using recursion and backtracking.
    Store all permutations, sort them lexicographically,
    find the current permutation, and return the next permutation.

    If the current permutation is the last permutation,
    return the first permutation (smallest arrangement).

    Approach:
    1. Store original permutation.
    2. Generate all permutations recursively using swapping.
    3. Sort all permutations lexicographically.
    4. Find the original permutation.
    5. Replace nums with the next permutation.

    Time Complexity:
    O(n! * n)

    Space Complexity:
    O(n! * n)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    void generatePermutations(int index,
                              vector<int>& nums,
                              vector<vector<int>>& all) {

        // Base Case
        if(index == nums.size()) {
            all.push_back(nums);
            return;
        }

        // Try every element at current position
        for(int i = index; i < nums.size(); i++) {

            swap(nums[index], nums[i]);

            generatePermutations(index + 1, nums, all);

            // Backtracking
            swap(nums[index], nums[i]);
        }
    }

    void nextPermutation(vector<int>& nums) {

        // Store original permutation
        vector<int> original = nums;

        // Store all permutations
        vector<vector<int>> all;

        // Sort array first
        sort(nums.begin(), nums.end());

        // Generate all permutations
        generatePermutations(0, nums, all);

        // Sort permutations lexicographically
        sort(all.begin(), all.end());

        // Find original permutation
        for(int i = 0; i < all.size(); i++) {

            if(all[i] == original) {

                // If original is last permutation
                if(i == all.size() - 1) {
                    nums = all[0];
                }

                // Otherwise assign next permutation
                else {
                    nums = all[i + 1];
                }

                return;
            }
        }
    }
};


/*
    Problem: 31. Next Permutation
    Platform: LeetCode
    Approach: Better Approach (Using STL next_permutation)

    Intuition:
    Generate all permutations in lexicographical order
    using the STL next_permutation() function.

    Store all permutations, find the current permutation,
    and replace it with the next permutation.

    If the current permutation is the last permutation,
    return the first permutation.

    Approach:
    1. Store original permutation.
    2. Sort array to start from smallest permutation.
    3. Generate all permutations using next_permutation().
    4. Find original permutation.
    5. Replace nums with next permutation.

    Time Complexity:
    O(n! * n)

    Space Complexity:
    O(n! * n)
*/

class Solution {
public:

    void nextPermutation(vector<int>& nums) {

        // Store original permutation
        vector<int> original = nums;

        // Store all permutations
        vector<vector<int>> all;

        // Start from smallest permutation
        sort(nums.begin(), nums.end());

        // Generate all permutations
        do {
            all.push_back(nums);

        } while(next_permutation(nums.begin(), nums.end()));

        // Find original permutation
        for(int i = 0; i < all.size(); i++) {

            if(all[i] == original) {

                // If original is last permutation
                if(i == all.size() - 1) {
                    nums = all[0];
                }

                // Otherwise assign next permutation
                else {
                    nums = all[i + 1];
                }

                return;
            }
        }
    }
};


/*
    Problem: 31. Next Permutation
    Platform: LeetCode
    Approach: Optimal Approach

    Intuition:
    We need to find the next lexicographically greater permutation.

    To get the next immediate permutation:
    1. Find the first decreasing element from the back
       (breaking point).
    2. Find the smallest element greater than it
       from the right side.
    3. Swap them.
    4. Reverse the suffix to make it minimum possible.

    Approach:
    1. Traverse from back and find index where:
           nums[i] < nums[i + 1]
    2. If no such index exists,
       reverse entire array.
    3. Otherwise find first element greater than nums[index]
       from the back.
    4. Swap them.
    5. Reverse elements after index.

    Time Complexity:
    O(n)

    Space Complexity:
    O(1)
*/

class Solution {
public:

    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        int index = -1;

        // Find breaking point
        for(int i = n - 2; i >= 0; i--) {

            if(nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // If array is last permutation
        if(index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find smallest greater element
        for(int i = n - 1; i > index; i--) {

            if(nums[i] > nums[index]) {

                swap(nums[i], nums[index]);
                break;
            }
        }

        // Reverse suffix
        reverse(nums.begin() + index + 1, nums.end());
    }
};