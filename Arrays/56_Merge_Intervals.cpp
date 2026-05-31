/*
    Problem: Merge Overlapping Subintervals

    Approach: Brute Force

    Intuition:
    - First sort intervals based on starting time.
    - For every interval, try to merge all overlapping intervals ahead of it.
    - Keep extending the ending point while overlaps exist.
    - Skip intervals that are already covered by a previously merged interval.
    - Store the final merged interval in the answer.

    Example:
    [1,3] [2,6] [8,10] [15,18]

    Start with [1,3]
    -> overlaps with [2,6]
    -> merged interval becomes [1,6]

    Store [1,6]
    Store [8,10]
    Store [15,18]

    Time Complexity: O(N^2)
    Space Complexity: O(N)  (excluding output array)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {

            int start = intervals[i][0];
            int end = intervals[i][1];

            // Interval already merged by a previous interval
            if(!ans.empty() && end <= ans.back()[1])
                continue;

            for(int j = i + 1; j < n; j++) {

                if(intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                }
                else {
                    break;
                }
            }

            ans.push_back({start, end});
        }

        return ans;
    }
};


/*
    Problem: Merge Overlapping Subintervals

    Approach: Sorting + Running Merged Interval (Optimal)

    Intuition:
    - Sort intervals by starting time.
    - Keep one interval called 'current' representing the
      merged interval formed so far.
    - For every next interval:
        * If it overlaps with current, extend current.
        * Otherwise, store current in answer and start
          a new current interval.
    - Finally, push the last current interval.

    Overlap Condition:
    next_start <= current_end

    Example:
    [1,3] [2,6] [8,10] [15,18]

    current = [1,3]

    [2,6] overlaps
    -> current = [1,6]

    [8,10] does not overlap
    -> store [1,6]
    -> current = [8,10]

    [15,18] does not overlap
    -> store [8,10]
    -> current = [15,18]

    Store last interval.

    Answer:
    [1,6] [8,10] [15,18]

    Time Complexity: O(N log N)
    Space Complexity: O(N)   (excluding sorting space)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        vector<int> current = intervals[0];

        for(int i = 1; i < n; i++) {

            if(intervals[i][0] <= current[1]) {

                current[1] = max(current[1], intervals[i][1]);
            }
            else {

                ans.push_back(current);

                current = intervals[i];
            }
        }

        ans.push_back(current);

        return ans;
    }
};