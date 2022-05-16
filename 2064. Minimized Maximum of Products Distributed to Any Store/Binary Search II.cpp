#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search(Min No. of pages)


   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 248 ms faster than: 68.18%
   Memory Usage: 143.9 MB less than: 6.95%
   Remarks:
*/

class Solution {
   public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, mid, high = *max_element(quantities.begin(), quantities.end()), res;

        while (low <= high) {
            mid = low + (high - low) / 2;
            // cout<<"Next"<<endl;
            // cout<<low<<" "<<mid<<" "<<high<<endl;

            if (isPossible(quantities, mid, n)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }

   private:
    bool isPossible(vector<int> quantities, int mid, int n) {
        int count = 0;
        for (auto quantity : quantities) {
            count += ceil((double)quantity / mid);
        }
        return count <= n;
    }
};