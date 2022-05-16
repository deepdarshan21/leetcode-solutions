#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search(Min No. of pages)


   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 566 ms faster than: 5.61%
   Memory Usage: 143.5 MB less than: 7.62%
   Remarks:
*/

class Solution {
   public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 0, mid, high = *max_element(quantities.begin(), quantities.end()), res;

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
        int i = 0;
        int temp = quantities[0];
        while (n && i < quantities.size()) {
            // quantities[i] -= mid;
            temp -= mid;
            // cout<<n<<" "<<i<<" - "<<temp<<endl;
            n--;
            if (temp <= 0) {
                i++;
                if (i < quantities.size()) {
                    temp = quantities[i];
                }
            }
        }
        if (i < quantities.size()) {
            // cout<<"false"<<endl;
            return false;
        }
        // cout<<"true"<<endl;
        return true;
    }
};