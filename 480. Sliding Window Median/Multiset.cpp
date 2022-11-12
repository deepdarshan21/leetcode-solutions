#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Priority Queue

   Edge Cases:

   Time Complexity: O((n-k)*klogk) Space: O(k)
   Status: Accepted
   Runtime: 97 ms faster than: 48.95%
   Memory Usage: 17.1 MB less than: 32.67%
   Remarks:
*/

class Solution {
   private:
    class MedianFinder {
       private:
        multiset<int, greater<int>> small;
        multiset<int> large;

       public:
        MedianFinder() {
        }

        void addNum(int num) {
            if (small.empty() || *small.begin() > num)
                small.insert(num);
            else
                large.insert(num);

            if (small.size() > (large.size() + 1)) {
                large.insert(*small.begin());
                small.erase(small.begin());
            }

            if (large.size() > (small.size() + 1)) {
                small.insert(*large.begin());
                large.erase(large.begin());
            }
        }
        void deleteNum(int num) {
            if (small.find(num) != small.end())
                small.erase(small.find(num));
            else
                large.erase(large.find(num));
        }

        double findMedian() {
            if (small.size() > large.size()) return *small.begin();
            if (large.size() > small.size()) return *large.begin();
            return (*small.begin() + (double)*large.begin()) / 2.0;
        }
    };

   public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        MedianFinder mf = MedianFinder();
        vector<double> res;
        int n = nums.size();
        for (int i = 0; i < k; i++) mf.addNum(nums[i]);
        res.push_back(mf.findMedian());
        for (int i = k; i < n; i++) {
            mf.deleteNum(nums[i - k]);
            mf.addNum(nums[i]);
            res.push_back(mf.findMedian());
        }
        return res;
    }
};