#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Floyd's Cycle-Finding Algorithm(Two Pointer)
        Use two pointers "slow" and "high" and increase the valus of "slow" slowly and "fast" fastly,
        if there is any sequence, then eventually sometime "slow" and "fast" will become equal => "false"
        if there is no sequence, then "slow" and "fast" will never brcome equal => true

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 5 ms faster than: 25.01%
   Memory Usage:  5.9MB less than: 63.83%
   Remarks:
*/

class Solution {
   public:
    bool isHappy(int n) {
        int fast, slow;
        slow = n;
        fast = nextInSequence(n);
        while (fast != 1 && fast != slow) {
            slow = nextInSequence(slow);
            fast = nextInSequence(nextInSequence(fast));
        }
        if (fast == 1) {
            return true;
        }
        return false;
    }

   private:
    int nextInSequence(int n) {
        int temp = 0;
        while (n != 0) {
            temp += pow(n % 10, 2);
            n /= 10;
        }
        return temp;
    }
};