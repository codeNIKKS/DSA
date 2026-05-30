/*
    LeetCode 18. 4 Sum

    Brute Force Approach

    Intuition:
    - Generate every possible quadruplet using 4 nested loops.
    - Check if the sum of the 4 elements equals the target.
    - Since duplicate quadruplets may occur, store them in a set.
    - Sort each valid quadruplet before inserting into the set so that
      different orders of the same elements are treated as identical.

    Approach:
    1. Use four loops to pick indices i, j, k, and l.
    2. Calculate the sum of nums[i], nums[j], nums[k], and nums[l].
    3. If the sum equals target:
         - Create a quadruplet.
         - Sort it.
         - Insert it into a set.
    4. Convert the set into a vector and return it.

    Time Complexity:
    - O(N^4) for generating all quadruplets.
    - O(4 log 4) ≈ O(1) for sorting each quadruplet.
    - Total: O(N^4)

    Space Complexity:
    - O(K) for storing unique quadruplets in the set,
      where K is the number of valid quadruplets.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        set<vector<int>> st;

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                for(int k = j + 1; k < n; k++) {

                    for(int l = k + 1; l < n; l++) {

                        long long sum =
                            (long long)nums[i] +
                            nums[j] +
                            nums[k] +
                            nums[l];

                        if(sum == target) {

                            vector<int> temp = {
                                nums[i],
                                nums[j],
                                nums[k],
                                nums[l]
                            };

                            sort(temp.begin(), temp.end());

                            st.insert(temp);
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};


/*
    LeetCode 18. 4 Sum

    Better Approach (Hashing)

    Intuition:
    - Instead of using 4 nested loops, fix the first two elements.
    - For the remaining part of the array, use a hashset to find
      the fourth required element in O(1) average time.
    - This reduces one loop and improves the complexity from O(N^4)
      to O(N^3).
    - A set is used to store unique quadruplets and avoid duplicates.

    Approach:
    1. Fix nums[i] using the first loop.
    2. Fix nums[j] using the second loop.
    3. Create a hashset for the current (i, j) pair.
    4. Traverse k from j + 1 to n - 1.
    5. Compute:
            fourth = target - nums[i] - nums[j] - nums[k]
    6. If fourth already exists in the hashset:
            quadruplet found.
    7. Sort the quadruplet and insert it into the set.
    8. Insert nums[k] into the hashset.
    9. Convert the set into a vector and return it.

    Time Complexity:
    - i loop      -> O(N)
    - j loop      -> O(N)
    - k loop      -> O(N)
    - Hash lookup -> O(1) average

    Total: O(N^3)

    Space Complexity:
    - O(N) for hashset
    - O(K) for storing unique answers

    Where K = number of valid quadruplets.
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        set<vector<int>> st;

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                unordered_set<long long> hashset;

                for(int k = j + 1; k < n; k++) {

                    long long fourth =
                        (long long)target
                        - nums[i]
                        - nums[j]
                        - nums[k];

                    if(hashset.find(fourth) != hashset.end()) {

                        vector<int> temp = {
                            nums[i],
                            nums[j],
                            nums[k],
                            (int)fourth
                        };

                        sort(temp.begin(), temp.end());

                        st.insert(temp);
                    }

                    hashset.insert(nums[k]);
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};


/*
    LeetCode 18. 4 Sum

    Optimal Approach (Sorting + Two Pointers)

    Intuition:
    - Sort the array first.
    - Fix the first two elements using loops i and j.
    - Use two pointers (k and l) to find the remaining two elements.
    - Since the array is sorted:
        * If sum < target, move k forward.
        * If sum > target, move l backward.
        * If sum == target, store the quadruplet.
    - Skip duplicates at every level to avoid repeated quadruplets.

    Approach:
    1. Sort the array.
    2. Fix nums[i].
       - Skip duplicate values of i.
    3. Fix nums[j].
       - Skip duplicate values of j.
    4. Initialize:
            k = j + 1
            l = n - 1
    5. While k < l:
         - Calculate the 4-element sum.
         - Move pointers according to comparison with target.
         - If a valid quadruplet is found:
             * Store it.
             * Move both pointers.
             * Skip duplicate values of k and l.
    6. Return all unique quadruplets.

    Time Complexity:
    - Sorting: O(N log N)
    - i loop: O(N)
    - j loop: O(N)
    - Two pointers: O(N)

    Total: O(N^3)

    Space Complexity:
    - O(1) excluding output array.
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 3; i++) {

            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            for(int j = i + 1; j < n - 2; j++) {

                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int k = j + 1;
                int l = n - 1;

                while(k < l) {

                    long long sum =
                        (long long)nums[i] +
                        nums[j] +
                        nums[k] +
                        nums[l];

                    if(sum < target) {
                        k++;
                    }
                    else if(sum > target) {
                        l--;
                    }
                    else {

                        ans.push_back(
                            {nums[i], nums[j], nums[k], nums[l]}
                        );

                        k++;
                        l--;

                        while(k < l && nums[k] == nums[k - 1])
                            k++;

                        while(k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                }
            }
        }

        return ans;
    }
};