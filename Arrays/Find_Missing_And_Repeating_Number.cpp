/*
=========================================================
Problem: Find Missing and Repeating Number
Approach: Brute Force (Count Frequency)
=========================================================

Intuition:
- For every number from 1 to N, count its occurrences
  in the array.
- If count == 2 -> Repeating Number.
- If count == 0 -> Missing Number.

Approach:
1. Iterate from 1 to N.
2. For each number, traverse the entire array and count
   its frequency.
3. Frequency 2 => repeating.
4. Frequency 0 => missing.
5. Return {repeating, missing}.

Time Complexity: O(N²)
Space Complexity: O(1)

=========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {

        int n = nums.size();

        int repeating = -1;
        int missing = -1;

        for(int i = 1; i <= n; i++) {

            int count = 0;

            for(int j = 0; j < n; j++) {
                if(nums[j] == i) {
                    count++;
                }
            }

            if(count == 2) {
                repeating = i;
            }
            else if(count == 0) {
                missing = i;
            }

            if(repeating != -1 && missing != -1) {
                break;
            }
        }

        return {repeating, missing};
    }
};


/*
=========================================================
Problem: Find Missing and Repeating Number
Approach: Better (Hashing / Frequency Array)
=========================================================

Intuition:
- Store the frequency of every number from 1 to N.
- The number with frequency 2 is the repeating number.
- The number with frequency 0 is the missing number.

Approach:
1. Create a frequency array of size (N + 1).
2. Traverse the given array and increment frequency.
3. Traverse from 1 to N:
   - freq[i] == 2 -> repeating number
   - freq[i] == 0 -> missing number
4. Return {repeating, missing}.

Time Complexity: O(N)
Space Complexity: O(N)

=========================================================
*/

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {

        int n = nums.size();

        vector<int> freq(n + 1, 0);

        for(int num : nums) {
            freq[num]++;
        }

        int repeating = -1;
        int missing = -1;

        for(int i = 1; i <= n; i++) {

            if(freq[i] == 2) {
                repeating = i;
            }

            if(freq[i] == 0) {
                missing = i;
            }
        }

        return {repeating, missing};
    }
};


/*
=========================================================
Problem: Find Missing and Repeating Number
Approach: Optimal (XOR)
=========================================================

Intuition:
- Let:
    X = Missing Number
    Y = Repeating Number

- XOR all array elements and numbers from 1 to N.

    xr = X ^ Y

- Since X != Y, xr will have at least one set bit.
- Find the rightmost set bit and divide all numbers
  into two groups based on that bit.
- XOR within each group to obtain X and Y.
- Finally determine which one is repeating by checking
  its frequency in the array.

Approach:
1. XOR all array elements and numbers from 1 to N.
2. Extract the rightmost set bit:
       mask = xr & ~(xr - 1)
3. Partition array elements and numbers 1..N into
   two groups using this bit.
4. XOR within both groups to obtain two candidates.
5. Count frequency of one candidate to identify
   repeating and missing numbers.
6. Return {repeating, missing}.

Time Complexity: O(N)
Space Complexity: O(1)

=========================================================
*/

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {

        int n = nums.size();

        int xr = 0;

        // XOR of array elements and numbers 1..N
        for(int i = 0; i < n; i++) {
            xr ^= nums[i];
            xr ^= (i + 1);
        }

        // Rightmost set bit
        int mask = xr & ~(xr - 1);

        int zero = 0;
        int one = 0;

        // Partition into two groups
        for(int i = 0; i < n; i++) {

            if(nums[i] & mask)
                one ^= nums[i];
            else
                zero ^= nums[i];

            if((i + 1) & mask)
                one ^= (i + 1);
            else
                zero ^= (i + 1);
        }

        // Determine which is repeating
        int cnt = 0;

        for(int num : nums) {
            if(num == zero)
                cnt++;
        }

        if(cnt == 2)
            return {zero, one};   // {repeating, missing}

        return {one, zero};       // {repeating, missing}
    }
};