#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Count number of one's for every element then check is it is one or not;

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 58 ms faster than: 16.58%
   Memory Usage: 6 MB less than: 24.22%
   Remarks:
*/

class Solution {
   public:
    int countPrimeSetBits(int left, int right) {
        const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int count = 0;
        for (int i = left; i <= right; i++) {
            int ones = 0;
            int n = i;
            while (n != 0) {
                n = n & (n - 1);
                ones++;
            }
            if (find(primes.begin(), primes.end(), ones) != primes.end()) count++;
        }
        return count;
    }
};