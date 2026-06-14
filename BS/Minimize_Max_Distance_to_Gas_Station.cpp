/*
=========================================================
📌 Problem: Minimize Max Distance to Gas Station
🔗 Platform: LeetCode / GFG

💡 Intuition:
We have k new gas stations to place.

At every step, place the next gas station in the interval
currently having the largest section length.

For each gap:
    arr[i+1] - arr[i]

Maintain how many new stations are inserted in every gap.

Current maximum section length of a gap:

    gapLength / (stationsInserted + 1)

For each of the k gas stations:
1. Find the gap with the largest current section length.
2. Insert a station there.
3. Update that gap's count.

After placing all k stations, compute the largest
section length among all gaps.

---------------------------------------------------------
✅ Approach (Brute Force Greedy Simulation)

1. Create howmany[] to store the number of stations
   inserted in each gap.
2. Repeat k times:
      - Scan all gaps.
      - Find the gap having maximum section length.
      - Insert a station in that gap.
3. Compute the answer from the final configuration.

---------------------------------------------------------
⏱️ Time Complexity:
O(k * n)

For every new gas station, we scan all gaps.

🗄️ Space Complexity:
O(n)

=========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {

        int n = arr.size();

        vector<int> howmany(n - 1, 0);

        for (int gasStation = 1; gasStation <= k; gasStation++) {

            long double maxSection = -1;
            int maxIndex = -1;

            for (int i = 0; i < n - 1; i++) {

                long double sectionLength =
                    (long double)(arr[i + 1] - arr[i]) /
                    (howmany[i] + 1);

                if (sectionLength > maxSection) {
                    maxSection = sectionLength;
                    maxIndex = i;
                }
            }

            howmany[maxIndex]++;
        }

        long double ans = -1;

        for (int i = 0; i < n - 1; i++) {

            long double sectionLength =
                (long double)(arr[i + 1] - arr[i]) /
                (howmany[i] + 1);

            ans = max(ans, sectionLength);
        }

        return ans;
    }
};


/*
=========================================================
📌 Problem: Minimize Max Distance to Gas Station
🔗 Platform: LeetCode / GFG

💡 Intuition:
Instead of scanning all gaps for every new gas station,
always directly access the gap having the largest current
section length.

Use a Max Heap (Priority Queue) storing:

    {currentSectionLength, gapIndex}

For every gas station insertion:
1. Extract the gap with the largest section length.
2. Insert a gas station in that gap.
3. Recalculate its new section length.
4. Push the updated gap back into the heap.

After placing all k stations, the heap top contains
the maximum distance between adjacent gas stations.

---------------------------------------------------------
✅ Approach (Priority Queue)

1. For each gap:
      gap = arr[i+1] - arr[i]

   Push:
      {gap, index}

   into a max heap.

2. Repeat k times:
      - Pop the largest gap.
      - Increase stations inserted in that gap.
      - Compute new section length:
            gap / (stationsInserted + 1)
      - Push updated value back.

3. Heap top after k insertions is the answer.

---------------------------------------------------------
⏱️ Time Complexity:
O((n + k) log n)

Building heap: O(n log n)
k insertions/removals: O(k log n)

🗄️ Space Complexity:
O(n)

=========================================================
*/

class Solution {
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {

        int n = arr.size();

        vector<int> howmany(n - 1, 0);

        priority_queue<pair<long double, int>> pq;

        for (int i = 0; i < n - 1; i++) {

            long double gap = arr[i + 1] - arr[i];

            pq.push({gap, i});
        }

        for (int gasStation = 1; gasStation <= k; gasStation++) {

            auto tp = pq.top();
            pq.pop();

            int sectionIndex = tp.second;

            howmany[sectionIndex]++;

            long double initialGap =
                arr[sectionIndex + 1] - arr[sectionIndex];

            long double newSectionLength =
                initialGap / (howmany[sectionIndex] + 1);

            pq.push({newSectionLength, sectionIndex});
        }

        return pq.top().first;
    }
};


/*
=========================================================
📌 Problem: Minimize Max Distance to Gas Station
🔗 Platform: LeetCode / GFG

💡 Intuition:
We need to minimize the maximum distance between
adjacent gas stations after adding k new stations.

Instead of deciding where to place stations directly,
binary search on the answer.

Assume:
    dist = maximum allowed distance

Can we ensure every adjacent distance is <= dist
using at most k new stations?

For a gap:

    gap = arr[i] - arr[i-1]

Stations needed:

    floor(gap / dist)

If gap is exactly divisible by dist, one station
count gets overcounted, so subtract 1.

If total stations required <= k,
then dist is achievable.

Otherwise, dist is too small.

---------------------------------------------------------
✅ Approach (Binary Search on Answer)

1. Search space:
      low = 0
      high = maximum gap

2. Binary search on distance.

3. For each mid:
      - Count stations required.
      - If required > k:
            distance too small
            move right
      - Else:
            try smaller distance

4. Continue until precision 1e-6.

---------------------------------------------------------
⏱️ Time Complexity:
O(n * log(maxGap / 1e-6))

≈ O(50 * n)

🗄️ Space Complexity:
O(1)

=========================================================
*/

class Solution {
public:

    int numOfStations(vector<int>& arr, long double dist) {

        int n = arr.size();
        int cnt = 0;

        for (int i = 1; i < n; i++) {

            long double gap = arr[i] - arr[i - 1];

            int stationsNeeded = gap / dist;

            if ((gap / dist) == stationsNeeded) {
                stationsNeeded--;
            }

            cnt += stationsNeeded;
        }

        return cnt;
    }

    long double minimiseMaxDistance(vector<int>& arr, int k) {

        int n = arr.size();

        long double low = 0;
        long double high = 0;

        for (int i = 1; i < n; i++) {
            high = max(high,
                       (long double)(arr[i] - arr[i - 1]));
        }

        while (high - low > 1e-6) {

            long double mid =
                low + (high - low) / 2.0;

            int cnt = numOfStations(arr, mid);

            if (cnt > k) {
                low = mid;
            }
            else {
                high = mid;
            }
        }

        return high;
    }
};