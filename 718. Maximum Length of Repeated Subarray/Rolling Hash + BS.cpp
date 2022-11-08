#include <bits/stdc++.h>
using namespace std;

/*
   Approach:Rolling Hash + Binary Search

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 54 ms faster than: 99.64%
   Memory Usage: 15.3 MB less than: 73.66%
   Remarks:
*/

class Solution {
   public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int low = 0, high = min(n, m), mid, res = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            // cout<<low<<" "<<mid<<" "<<high<<endl;
            if (isValid(nums1, nums2, mid)) {
                // cout<<"yes"<<endl;
                res = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return res;
    }

   private:
    bool isValid(vector<int>& nums1, vector<int>& nums2, int k) {
        long long mod = 1e9 + 7;
        set<long long> hashes;
        long long hash = 0;
        long long prime = 10;
        long long power = 1;
        for (int i = 0; i < k; i++) {
            hash = (hash * prime + nums1[i] + 1) % mod;
            if (i != 0)
                power = (power * prime) % mod;
        }
        // power/=101;
        // cout<<power<<endl;
        // cout<<hash<<endl;
        hashes.insert(hash);
        for (int i = k; i < nums1.size(); i++) {
            hash = ((hash - ((nums1[i - k] + 1) * power) % mod + mod) * prime + nums1[i] + 1) % mod;
            // cout<<hash<<endl;
            hashes.insert(hash);
        }
        hash = 0;
        for (int i = 0; i < k; i++) hash = (hash * prime + nums2[i] + 1) % mod;
        if (hashes.find(hash) != hashes.end()) return true;
        for (int i = k; i < nums2.size(); i++) {
            hash = ((hash - ((nums2[i - k] + 1) * power) % mod + mod) * prime + nums2[i] + 1) % mod;
            if (hashes.find(hash) != hashes.end()) return true;
        }
        return false;
    }
};