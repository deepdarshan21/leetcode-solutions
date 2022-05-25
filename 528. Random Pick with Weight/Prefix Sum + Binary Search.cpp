#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Prifix Sum + Binary Search
        Firstly, make a vector to store the sum element previous to that index.
        Secondly, take a random number form 1 to sum.
        Then, apply binary search to find the index in new array whose value is either equal to or
        just greater than the choosen random number.

   Edge Cases:

   Time Complexity: O(logn) Space: O(1)
   Status: Accepted
   Runtime: 148 ms faster than: 29.78%
   Memory Usage: 40.5 MB less than: 23.18%
   Remarks:
*/

class Solution {
   private:
    vector<int> arr;
    // srand(time(0));

   public:
    Solution(vector<int>& w) {
        int sum = 0;
        for (auto itr : w) {
            sum += itr;
            arr.push_back(sum);
        }
    }

    int pickIndex() {
        int num = rand() % arr[arr.size() - 1] + 1;
        // int res = 0;
        int low = 0, mid, high = arr.size() - 1;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (arr[mid] < num) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */