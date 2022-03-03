#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 4 ms faster than: 49.49%
   Memory Usage: 8 MB less than: 5.06%
   Remarks:
*/

class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count = 0, size;
        if (nums.size() < 3) {
            return count;
        }
        for (int i = 0; i < nums.size() - 2; i++) {
            size = 3;
            while ((i + size) <= nums.size()) {
                vector<int> sliced(nums.begin() + i, nums.begin() + i + size - 1);
                if (isArithmetic(sliced)) {
                    count++;
                } else {
                    break;
                }
                size++;
            }
        }
        return count;
    }

   private:
    bool isArithmetic(vector<int> slicedNums) {
        int diff = slicedNums[1] - slicedNums[0];
        for (int i = 2; i < slicedNums.size(); i++) {
            if ((slicedNums[i] - slicedNums[i - 1]) != diff) {
                return false;
            }
        }
        return true;
    }
};