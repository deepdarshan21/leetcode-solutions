#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Bucket Sort

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 435 ms faster than: 7.62%
   Memory Usage: 124.1 MB less than: 11.60%
   Remarks:
*/

class Solution {
   private:
    vector<int> bucketSort(vector<int> nums) {
        int maxEle = *max_element(nums.begin(), nums.end());
        int bucketSize = 10, maxPass = log10(maxEle) + 1;
        vector<vector<int>> buckets(bucketSize);
        vector<int> tmpNum(nums.size());
        int currPass = 0;
        while (currPass < maxPass) {
            for (auto num : nums) {
                int tmp = (num % (int)(pow(10, currPass + 1))) / pow(10, currPass);
                // cout<<tmp<<"-"<<num<<" ";
                buckets[tmp].push_back(num);
            }
            // cout<<endl;
            // cout<<"Check"<<endl;
            int i = 0;
            for (auto bucket : buckets) {
                // cout<<bucket.size()<<" ";
                for (int num : bucket) {
                    nums[i++] = num;
                }
            }
            // cout<<endl;
            // for(int num: nums) cout<<num<<" ";
            // cout<<endl;
            for (int i = 0; i < 10; i++) buckets[i] = {};
            currPass++;
        }
        return nums;
    }

   public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        nums = bucketSort(nums);
        // for(int num: nums) cout<<num<<" ";
        // cout<<endl;
        int res = 0;
        for (int i = 1; i < n; i++) res = max(res, nums[i] - nums[i - 1]);
        return res;
    }
};