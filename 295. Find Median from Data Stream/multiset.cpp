#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Compiler Error
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Advance not suported in leetcode
*/

class MedianFinder {
   private:
    multiset<int> nums;

   public:
    MedianFinder() {
    }

    void addNum(int num) {
        nums.insert(num);
    }

    double findMedian() {
        int n = nums.size();
        auto itr = nums.begin();
        advance(nums, n / 2);
        if (n % 2 == 0) {
            auto itr1 = itr--;
            return (*itr + *itr1) / 2.0;
        }
        return *itr;
    }
};