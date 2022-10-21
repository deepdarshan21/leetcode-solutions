#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Use multiset to store the elements in sorted order
        Then use lower bound and try to find the element as same value or greater, if diff is smaller then valueDiff => return true
        else check nums[i] with element just before found element to check if diff is smaller then valueDiff => return true
        insert nums[i] in multiset
        if(i>=indexDiff) remove nums[i-indexDiff];

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 419 ms faster than: 39.45%
   Memory Usage: 79.2 MB less than: 24.56%
   Remarks:
*/

class Solution {
   public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        multiset<int> st;
        for (int i = 0; i < n; i++) {
            auto itr = st.lower_bound(nums[i]);
            if (itr != st.end() && abs(nums[i] - *itr) <= valueDiff) return true;
            if (itr != st.begin() && abs(nums[i] - *(--itr)) <= valueDiff) return true;
            st.insert(nums[i]);
            if (i >= indexDiff) {
                st.erase(nums[i - indexDiff]);
            }
        }
        return false;
    }
};