class Solution {
public:
    int countNumbersWithUniqueDigits(int n, int currAns = 0) {
        if (n == 0) {
            return currAns + 1;
        }
        if (n == 1) {
            return currAns + 10;
        }
        int ans, curr = 9;
        ans = 9 * 9;
        curr--;
        for (int i = 3; i <= n; i++) {
            ans *= curr;
            curr--;
        }
        return currAns + ans + countNumbersWithUniqueDigits(n - 1);
    }
};