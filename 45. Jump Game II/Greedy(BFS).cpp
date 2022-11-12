#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy(BFS)
        We can iterate over all indices maintaining the furthest reachable position from current
        index - maxReachable and currently furthest reached position - lastJumpedPos. Everytime
        we will try to update lastJumpedPos to furthest possible reachable index - maxReachable.

        Updating the lastJumpedPos separately from maxReachable allows us to maintain track of
        minimum jumps required. Each time lastJumpedPos is updated, jumps will also be updated and
        store the minimum jumps required to reach lastJumpedPos (On the contrary, updating jumps
        with maxReachable won't give the optimal (minimum possible) value of jumps required).

        We will just return it as soon as lastJumpedPos reaches(or exceeds) last index.

        We can try to understand the steps in code below as analogous to those in BFS as -

            1. maxReachable = max(maxReachable, i + nums[i]) : Updating the range of next level.
               Similar to queue.push(node) step of BFS but here we are only greedily storing the
               max reachable index on next level.

            2. i == lastJumpedPos : When it becomes true, current level iteration has been completed.

            3. lastJumpedPos = maxReachable : Set range till which we need to iterate the next level

            4. jumps++ : Move on to the next level.

            5. return jumps : The final answer will be number of levels in BFS traversal.


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 10 ms faster than: 99.05%
   Memory Usage: 16.6 MB less than: 53.89%
   Remarks:
*/

class Solution {
   public:
    int jump(vector<int>& nums) {
        int n = nums.size(), maxReachable = 0, lastPos = 0, i = 0, jump = 0;
        while (lastPos < (n - 1)) {
            maxReachable = max(maxReachable, i + nums[i]);
            if (i == lastPos) {
                lastPos = maxReachable;
                jump++;
            }
            i++;
        }
        return jump;
    }
};