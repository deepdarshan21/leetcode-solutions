#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status:
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int maxFrequency(vector<int>& nums, int k) {
        auto freq = [&](int check) {
            int count = 0, freqCount = 0;
            // cout<<check<<endl;
            for (auto num : nums) {
                if (num <= check) {
                    count += (check - num);
                    freqCount++;
                }
                // cout<<" "<<num<<" "<<count<<endl;
                if (count > k) {
                    return 0;
                }
                // freqCount++;
            }
            // cout<<"      "<<freqCount<<endl;
            return freqCount;
        };
        int low = *min_element(nums.begin(), nums.end()), mid, high = *max_element(nums.begin(), nums.end());
        int res;

        while (low <= high) {
            mid = low + (high - low) / 2;
            int temp = freq(mid);
            // cout<<mid<<" "<<temp<<endl;
            if (temp > 0) {
                res = temp;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};