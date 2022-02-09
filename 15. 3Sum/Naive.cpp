#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Brute Force
        First sort the input vector and  then make every possible combination from it
        and check if thier sum is 0 or not

   Edge Cases:


   Time Complexity: O(n^3) Space: O(n^3)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
*/

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> tripletsSet;
        vector<int> triplet;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    int tempSum = nums[i] + nums[j] + nums[k];

                    if (tempSum == 0) {
                        triplet.push_back(nums[i]);
                        triplet.push_back(nums[j]);
                        triplet.push_back(nums[k]);
                        tripletsSet.insert(triplet);
                        triplet.clear();
                    }
                }
            }
        }
        vector<vector<int>> triplets(tripletsSet.begin(), tripletsSet.end());
        return triplets;
    }
};