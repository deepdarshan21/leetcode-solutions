#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Segement Tree

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 1736 ms faster than: 5.7%
   Memory Usage: 176.8 MB less than: 18%
   Remarks:
*/

class NumArray {
   private:
    vector<int> tree;
    vector<int> arr;
    int constructST(vector<int>& nums, int low, int high, int idx) {
        if (low == high) {
            return tree[idx] = nums[low];
        }
        int mid = low + (high - low) / 2;
        return tree[idx] = constructST(nums, low, mid, 2 * idx + 1) + constructST(nums, mid + 1, high, 2 * idx + 2);
    }

   public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) arr.push_back(nums[i]);
        tree.resize(4 * n);
        constructST(nums, 0, n - 1, 0);
    }

    void update(int index, int val) {
        int diff = val - arr[index];
        arr[index] = val;
        auto updateST = [&](auto updateST, int low, int high, int idx) {
            if (index < low || index > high) return;
            tree[idx] += diff;
            if (low < high) {
                int mid = low + (high - low) / 2;
                updateST(updateST, low, mid, 2 * idx + 1);
                updateST(updateST, mid + 1, high, 2 * idx + 2);
            }
        };
        updateST(updateST, 0, arr.size() - 1, 0);
    }

    int sumRange(int left, int right) {
        auto rangeSum = [&](auto rangeSum, int low, int high, int idx) {
            if (high < left || low > right) return 0;
            if (left <= low && right >= high) return tree[idx];
            int mid = low + (high - low) / 2;
            return rangeSum(rangeSum, low, mid, 2 * idx + 1) + rangeSum(rangeSum, mid + 1, high, 2 * idx + 2);
        };
        return rangeSum(rangeSum, 0, arr.size() - 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */