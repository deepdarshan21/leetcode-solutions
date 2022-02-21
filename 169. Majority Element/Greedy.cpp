#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy
        Count the frequency of selected element, if element other then selected comes then uncount,
        if count of selected element is 0 then select new element.

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 11 ms faster than: 98.46%
   Memory Usage: 19.5 MB less than: 99.35%
   Remarks: Freq of one of the element must be greater then "nums.size()/2"
*/

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int selected, count = 0;
        for (auto i : nums) {
            if (count == 0) {
                selected = i;
                count++;
            } else {
                if (selected == i) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        // int countSelected = 0;
        // for (auto i : nums) {
        //     if (i == selected) {
        //         countSelected++;
        //     }
        // }
        return selected;
    }
};