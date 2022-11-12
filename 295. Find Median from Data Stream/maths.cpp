#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: formula 3*median = 2*mean + mode is not true in all cases
*/

class MedianFinder {
   private:
    unordered_map<int, int> mp;
    int noOfElements, noOfModeElements, maxFreq;
    double mean, mode;

   public:
    MedianFinder() {
        noOfElements = 0;
        noOfModeElements = 0;
        maxFreq = 0;
        mean = 0;
        mode = 0;
    }

    void addNum(int num) {
        mean = (mean * noOfElements + num) / (noOfElements + 1);
        noOfElements++;
        mp[num]++;
        if (maxFreq < mp[num]) {
            mode = num;
            noOfModeElements = 1;
            maxFreq = mp[num];
        } else if (maxFreq == mp[num]) {
            mode = (mode * maxFreq * noOfModeElements + num) / (noOfModeElements + 1);
            noOfModeElements++;
        }
    }

    double findMedian() {
        double median = 0;
        median = (2 * mean + mode) / 3;
        return median;
    }
};
