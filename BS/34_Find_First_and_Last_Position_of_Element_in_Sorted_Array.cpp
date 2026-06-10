/*
    LeetCode 34: Find First and Last Position of Element in Sorted Array

    Intuition:
    Since the array is sorted, Binary Search can be used to efficiently
    locate the first and last occurrence of the target element.

    Approach:
    1. Perform a Binary Search to find the first occurrence:
       - If target is found, store the index and continue searching
         on the left half.
    2. Perform another Binary Search to find the last occurrence:
       - If target is found, store the index and continue searching
         on the right half.
    3. Return {firstOccurrence, lastOccurrence}.

    Time Complexity:
    O(log n) + O(log n) = O(log n)

    Space Complexity:
    O(1)
*/
#include <vector>
using namespace std;
class Solution {
public:
    int firstOccurrence(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int lastOccurrence(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int first = firstOccurrence(nums, target);

        if (first == -1)
            return {-1, -1};

        int last = lastOccurrence(nums, target);

        return {first, last};
    }
};