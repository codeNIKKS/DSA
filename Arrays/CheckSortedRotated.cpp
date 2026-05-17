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
