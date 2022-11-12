#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class MedianFinder {
   private:
    vector<int> nums;

   public:
    MedianFinder() {
    }

    void addNum(int num) {
        nums.push_back(num);
    }

    double findMedian() {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (n % 2 == 0) {
            return (nums[n / 2] + nums[n / 2 + 1]) / 2.0;
        }
        return nums[n / 2] * 1.0;
    }
};