#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(1) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 72.32%
   Memory Usage: 6.2 MB less than: 79.36%
   Remarks:
*/

class Solution {
   public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string res = "";
        int temp = 0, d1 = 0, n1 = 0;
        while (num != 0) {
            temp = (num % 10) * pow(10, d1) + temp;
            num /= 10;
            d1++;
            if (d1 == 3) {
                // cout<<"here"<<endl;
                // cout<<temp<<endl;
                string tmp = res.size() > 0 ? " " : "";
                // cout<<"xxx -> "<<res<<endl;
                if (temp > 0) res = help(temp) + value(n1) + tmp + res;
                d1 = 0;
                temp = 0;
                n1++;
            }
        }
        if (d1 != 0) {
            string tmp = res.size() > 0 ? " " : "";
            // cout<<res<<endl;
            if (temp > 0) res = help(temp) + value(n1) + tmp + res;
            // cout<<res<<endl;
            d1 = 0;
            temp = 0;
            n1++;
        }
        return res;
    }
    string value(int n) {
        if (n == 0) return "";
        if (n == 1) return " Thousand";
        if (n == 2) return " Million";
        if (n == 3) return " Billion";
        return "";
    }
    string help(int temp) {
        string res = "";
        int temp1 = temp / 100;
        // cout<<temp%100<<endl;
        if (temp1 > 0) res += getDigitInWords(temp1) + " Hundred";
        // cout<<res<<endl;
        if (temp % 100 > 0 && temp1 > 0) res += " ";
        if (temp % 100 > 0) res += getDigitInWords(temp % 100);
        // cout<<res<<endl;
        return res;
    }
    string getDigitInWords(int temp) {
        // cout<<"check "<<temp<<endl;
        if (temp == 10) return "Ten";
        if (temp == 11) return "Eleven";
        if (temp == 12) return "Twelve";
        if (temp == 13) return "Thirteen";
        if (temp == 14) return "Fourteen";
        if (temp == 15) return "Fifteen";
        if (temp == 16) return "Sixteen";
        if (temp == 17) return "Seventeen";
        if (temp == 18) return "Eighteen";
        if (temp == 19) return "Nineteen";
        int temp1 = temp / 10;
        if (temp1 > 1) {
            string tmp = temp % 10 > 0 ? " " : "";
            if (temp1 == 2) return "Twenty" + tmp + getDigitInWords(temp % 10);
            if (temp1 == 3) return "Thirty" + tmp + getDigitInWords(temp % 10);
            if (temp1 == 4) return "Forty" + tmp + getDigitInWords(temp % 10);
            if (temp1 == 5) return "Fifty" + tmp + getDigitInWords(temp % 10);
            if (temp1 == 6) return "Sixty" + tmp + getDigitInWords(temp % 10);
            if (temp1 == 7) return "Seventy" + tmp + getDigitInWords(temp % 10);
            if (temp1 == 8) return "Eighty" + tmp + getDigitInWords(temp % 10);
            if (temp1 == 9) return "Ninety" + tmp + getDigitInWords(temp % 10);
        }

        if (temp == 0) return "";
        if (temp == 1) return "One";
        if (temp == 2) return "Two";
        if (temp == 3) return "Three";
        if (temp == 4) return "Four";
        if (temp == 5) return "Five";
        if (temp == 6) return "Six";
        if (temp == 7) return "Seven";
        if (temp == 8) return "Eight";
        if (temp == 9) return "Nine";
        return "";
    }
};