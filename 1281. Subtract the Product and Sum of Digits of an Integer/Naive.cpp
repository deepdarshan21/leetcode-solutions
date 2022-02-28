#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6 MB less than: 26.57%
   Remarks:
*/

class Solution {
   public:
    int subtractProductAndSum(int n) {
        int sum, product;
        sum = 0;
        product = 1;
        while (n != 0) {
            sum += n % 10;
            product *= n % 10;
            n /= 10;
        }
        return product - sum;
    }
};