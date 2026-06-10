/*
    LeetCode 81. Search in Rotated Sorted Array II

    Approach:
    - Use Binary Search on the rotated sorted array.
    - One half of the array will always be sorted.
    - Duplicates create ambiguity when:
            nums[low] == nums[mid] == nums[high]
      In this case, we cannot determine the sorted half,
      so shrink the search space from both ends.

    Algorithm:
    1. Find mid.
    2. If nums[mid] == target, return true.
    3. Handle duplicate ambiguity by moving low++ and high--.
    4. Determine the sorted half.
    5. Check whether target lies inside the sorted half.
    6. Discard the other half.
    7. Continue until search space becomes empty.

    Time Complexity:
    - Average: O(log N)
    - Worst Case: O(N)  (when duplicates force linear shrinking)

    Space Complexity:
    - O(1)
*/
#include <vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return true;

            // Remove duplicate ambiguity
            if (nums[low] == nums[mid] &&
                nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // Left half sorted
            if (nums[low] <= nums[mid]) {

                if (nums[low] <= target &&
                    target < nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            // Right half sorted
            else {

                if (nums[mid] < target &&
                    target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};