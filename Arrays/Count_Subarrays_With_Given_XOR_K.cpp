/*
========================================================
Problem: Count Subarrays With Given XOR K
Approach: Brute Force
========================================================

Intuition:
- Generate all possible subarrays.
- For each subarray, calculate its XOR.
- If the XOR equals k, increment the count.

Approach:
1. Fix a starting index i.
2. Maintain a running XOR variable xorr.
3. Extend the subarray from i to n-1 using j.
4. Update XOR as:
       xorr ^= nums[j]
5. If xorr == k, increment count.
6. Return the total count.

Time Complexity: O(N^2)
Space Complexity: O(1)

========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysWithXorK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int xorr = 0;

            for (int j = i; j < n; j++) {
                xorr ^= nums[j];

                if (xorr == k) {
                    count++;
                }
            }
        }

        return count;
    }
};


/*
========================================================
Problem: Count Subarrays With Given XOR K
Approach: Optimal (Prefix XOR + Hash Map)
========================================================

Intuition:
- Let prefix XOR till index i be xorr.
- XOR of subarray [l...r] can be written as:
      prefixXor[r] ^ prefixXor[l-1]
- We need:
      prefixXor[r] ^ prefixXor[l-1] = k
- Rearranging:
      prefixXor[l-1] = prefixXor[r] ^ k
- Therefore, for every current prefix XOR,
  we look for (currentXor ^ k) in the hashmap.
- The hashmap stores frequencies of previously
  encountered prefix XOR values.

Approach:
1. Maintain running prefix XOR (xorr).
2. Store frequencies of prefix XORs in a hashmap.
3. Initialize mp[0] = 1 to handle subarrays
   starting from index 0.
4. For every element:
      xorr ^= nums[i]
5. Compute:
      rem = xorr ^ k
6. If rem exists in hashmap, add its frequency
   to the answer.
7. Store/update current prefix XOR in hashmap.
8. Return total count.

Time Complexity: O(N)
Space Complexity: O(N)

========================================================
*/

class Solution {
public:
    int subarraysWithXorK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int xorr = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            xorr ^= nums[i];

            int rem = xorr ^ k;

            if (mp.find(rem) != mp.end()) {
                count += mp[rem];
            }

            mp[xorr]++;
        }

        return count;
    }
};