#include <bits/stdc++.h>
using namespace std;

// PROBLEM:
// Rotate Array By K Places



// BRUTE FORCE APPROACH
// Store rotated elements in a temporary array.
// Then copy all elements back into original array.
//
// TC: O(n)
// SC: O(n)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;

        vector<int> temp(n);

        // Store last k elements at beginning
        for(int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }

        // Store remaining elements
        for(int i = 0; i < n - k; i++) {
            temp[k + i] = nums[i];
        }

        // Copy back to original array
        for(int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
    }
};

// BETTER APPROACH
// Store last k elements in a temporary array.
// Shift remaining elements to the right.
// Then place stored elements at beginning.
//
// TC: O(n)
// SC: O(k)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        if(n == 0) return;

        k = k % n;

        vector<int> temp(k);

        // Store last k elements
        for(int i = 0; i < k; i++) {
            temp[i] = nums[n-k+i];
        }

        // Shift remaining elements
        for(int i = n-k-1; i >= 0; i--) {
            nums[k+i] = nums[i];
        }

        // Place stored elements at beginning
        for(int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};

// OPTIMAL APPROACH
// Reverse entire array.
// Reverse first k elements.
// Reverse remaining n-k elements.
//
// TC: O(n)
// SC: O(1)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        k = k % n;

        // Reverse whole array
        reverse(nums.begin(), nums.end());

        // Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Reverse remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};