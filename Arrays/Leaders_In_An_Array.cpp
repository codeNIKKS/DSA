/*
    Problem: Leaders in an Array
    Difficulty: Medium

    A leader in an array is an element that is strictly greater
    than all the elements to its right side.

    ---------------------------------------------------------
    Brute Force Approach
    ---------------------------------------------------------

    Intuition:
    For every element, check all elements to its right.
    If no greater element exists on the right side,
    then that element is a leader.

    Approach:
    1. Traverse each element using outer loop.
    2. For every element, traverse all elements to its right.
    3. If any greater element is found:
            -> it is not a leader.
    4. Otherwise push it into answer vector.

    Time Complexity: O(N^2)
    Space Complexity: O(N)   // for storing answer
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans;

        for(int i = 0; i < n; i++) {

            bool leader = true;

            for(int j = i + 1; j < n; j++) {

                if(nums[j] > nums[i]) {
                    leader = false;
                    break;
                }
            }

            if(leader) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};


/*
    Problem: Leaders in an Array
    Difficulty: Medium

    A leader in an array is an element that is strictly greater
    than all the elements to its right side.

    ---------------------------------------------------------
    Optimal Approach
    ---------------------------------------------------------

    Intuition:
    While traversing from right to left, keep track of the
    maximum element seen so far.

    If the current element is greater than the maximum element
    on its right side, then it is a leader.

    Approach:
    1. Start traversing from the last element.
    2. Maintain a variable 'maxi' storing the maximum element
       seen so far from the right side.
    3. If nums[i] > maxi:
            -> it is a leader.
            -> add it to answer vector.
            -> update maxi.
    4. Since leaders are collected from right to left,
       reverse the answer vector at the end.

    Time Complexity: O(N)
    Space Complexity: O(N)   // for storing answer
*/

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans;

        int maxi = nums[n - 1];

        ans.push_back(nums[n - 1]);

        for(int i = n - 2; i >= 0; i--) {

            if(nums[i] > maxi) {

                ans.push_back(nums[i]);

                maxi = nums[i];
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};