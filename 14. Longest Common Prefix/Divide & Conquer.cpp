#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Divide and Conquer
       First devide the vector into single strings and then find prefix in them

   Edge Cases:
       1. Size of vector is 0

   Time Complexity: O()
   Space: O()
*/

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        } else if (strs.size() == 1) {
            return strs[0];
        } else {
            return divide(strs, 0, strs.size());
        }
    }

   private:
    string divide(vector<string> strs, int low, int high) {
        if (low == high) {
            return strs[low];
        } else {
            int mid = low + (high - low) / 2;
            string left = divide(strs, low, mid);
            string right = divide(strs, mid + 1, high);
            return conquer(left, right);
        }
    }
    string conquer(string left, string right) {
        int minLength = min(left.size(), right.size());
        for (int i = 0; i < minLength; i++) {
            if (left[i] != right[i]) {
                return left.substr(0, i);
            }
        }
        return left.substr(0, minLength);
    }
};