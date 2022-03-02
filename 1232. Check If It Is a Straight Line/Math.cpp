#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math
        Find slope between first two points and that slope must be equal to slope between every two points

   Edge Cases:
        1. If x coordinates are same => compare for same x coordinate not for slope.

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 11 ms faster than: 65.34%
   Memory Usage: 10.1 MB less than: 40.96%
   Remarks:
*/

class Solution {
   public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int xConstant;
        float slope, temp;
        bool slopeCheck = true;
        if ((coordinates[1][0] - coordinates[0][0]) != 0) {
            slope = (coordinates[1][1] - coordinates[0][1]) / ((coordinates[1][0] - coordinates[0][0]) * 1.0);
        } else {
            slopeCheck = false;
            xConstant = coordinates[0][0];
        }
        for (int i = 2; i < coordinates.size(); i++) {
            if (slopeCheck) {
                if ((coordinates[i][0] - coordinates[i - 1][0]) == 0) {
                    return false;
                } else {
                    temp = (coordinates[i][1] - coordinates[i - 1][1]) / ((coordinates[i][0] - coordinates[i - 1][0]) * 1.0);
                    if (temp != slope) {
                        return false;
                    }
                }
            } else {
                if ((coordinates[i][0] - coordinates[i - 1][0]) != 0) {
                    return false;
                } else {
                    temp = coordinates[i][0];
                    if (temp != xConstant) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};