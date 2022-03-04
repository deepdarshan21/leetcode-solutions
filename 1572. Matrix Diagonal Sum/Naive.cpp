#include <bits/stdc++.h>
using namespace std;

/*
   Approach:
        Sum the elements of both the digonals and if the size of given matrix is odd then we added
        the middle element twice, so remove that element at last

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status:
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        for (int i = 0; i < mat.size(); i++) {
            sum += mat[i][i] + mat[i][mat.size() - 1 - i];
        }
        if (mat.size() % 2 == 1) {
            sum -= mat[mat.size() / 2][mat.size() / 2];
        }
        return sum;
    }
};