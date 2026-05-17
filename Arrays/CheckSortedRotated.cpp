#include <vector>
using namespace std;
// PROBLEM:
// Check if Array Is Sorted and Rotated

// BRUTE FORCE APPROACH
// Try every rotation, create rotated array,
// then check if sorted.
//
// TC: O(n²)
// SC: O(n)

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            int index = 0;
            for(int j = i; j < n; j++) {

                arr[index++] = nums[j];
            }
            for(int j = 0; j < i; j++) {

                arr[index++] = nums[j];
            }
            int k;
            for(k = 0; k < n - 1; k++) {

                if(arr[k] > arr[k + 1]) {
                    break;
                }
            }
            if(k == n - 1) {
                return true;
            }
        }
        return false;
    }
};


// BETTER APPROACH
// Instead of creating a new rotated array,
// directly check every possible rotation
// using circular traversal.
//
// (i + j) % n helps simulate rotation
// without extra space.

// TC: O(n^2)
// SC: O(1)

class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();

        // Try every rotation starting point
        for(int i = 0; i < n; i++) {

            int j;

            // Check if current rotation is sorted
            for(j = 0; j < n - 1; j++) {

                if(nums[(i + j) % n] > nums[(i + j + 1) % n]) {
                    break;
                }
            }

            // Entire rotation is sorted
            if(j == n - 1) {
                return true;
            }
        }

        return false;
    }
};


// OPTIMAL APPROACH
// Traverse the array once and count
// how many times sorted order breaks.
//
// A sorted rotated array can have
// at most one break point.
//
// Circular traversal helps compare
// last element with first element.

// TC: O(n)
// SC: O(1)

class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();
        int breaks = 0;

        for(int i = 0; i < n; i++) {

            // Count order violations
            if(nums[i % n] > nums[(i + 1) % n]) {
                breaks++;
            }

            // More than one break => invalid
            if(breaks > 1) {
                return false;
            }
        }

        return true;
    }
};