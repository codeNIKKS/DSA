/*
========================================================
🔹 Problem: Nth Root Of M
🔹 Platform: GFG
🔹 Topic: Binary Search on Answers
========================================================

🧠 Intuition:
- We need to find an integer x such that:
      x^N = M
- If no such integer exists, return -1.
- The search space is from 1 to M.
- For every candidate 'mid', compute mid^N:
    • If mid^N == M → answer found.
    • If mid^N > M  → search left half.
    • If mid^N < M  → search right half.
- To avoid unnecessary multiplications, stop as soon as
  the computed value exceeds M.

--------------------------------------------------------
✅ Approach:
1. Apply Binary Search on range [1, M].
2. Create a helper function:
      func(mid, N, M)
   Returns:
      1 → mid^N == M
      2 → mid^N > M
      0 → mid^N < M
3. Based on helper result:
      1 → return mid
      2 → high = mid - 1
      0 → low = mid + 1
4. If no exact root exists, return -1.

--------------------------------------------------------
⏱️ Time Complexity:
O(N * log M)

📦 Space Complexity:
O(1)

========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int func(int mid, int n, int m) {
        long long ans = 1;

        for(int i = 1; i <= n; i++) {
            ans *= mid;

            if(ans > m)
                return 2;
        }

        if(ans == m) return 1;

        return 0;
    }

    int NthRoot(int N, int M) {
        if(M < 2) return M;

        int low = 1;
        int high = M;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int midN = func(mid, N, M);

            if(midN == 1)
                return mid;
            else if(midN == 2)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return -1;
    }
};