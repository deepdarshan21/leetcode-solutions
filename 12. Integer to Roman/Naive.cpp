#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Brute Force
        First count the number of digits in given number, and then itrate to every digit
        in number and find equivalant roman value and add thet to final equivalant roman value

   Edge Cases:


   Time Complexity: O(log(n)) Space: O(1)
   Status: Accepted
   Runtime: 7 ms faster than: 74.79%
   Memory Usage: 6.2 MB less than: 41.40%
*/

class Solution {
   public:
    string intToRoman(int num) {
        int place = 0, noOfDigits = 0;
        int temp = num;
        while (temp > 0) {
            noOfDigits++;
            temp /= 10;
        }
        string equivalentRoman = "";
        int digit;
        while (noOfDigits > 0) {
            digit = num / pow(10, noOfDigits - 1);
            equivalentRoman += equivalentRomanForPlace(digit, noOfDigits - 1);
            num = num % (int)pow(10, noOfDigits - 1);
            noOfDigits--;
        }
        return equivalentRoman;
    }

   private:
    string equivalentRomanForPlace(int digit, int place) {
        string one = "I", five = "V", ten = "X", fifty = "L", hundred = "C", fiveHundred = "D", thousand = "M";
        string roman = "";
        if (place == 3) {
            if (digit <= 3) {
                for (int i = 0; i < digit; i++) {
                    roman += "M";
                }
            }
        } else if (place == 2) {
            if (digit <= 3) {
                for (int i = 0; i < digit; i++) {
                    roman += "C";
                }
            } else if (digit == 4) {
                roman += "CD";
            } else if (digit == 5) {
                roman = "D";
            } else if (digit <= 8) {
                roman += "D";
                for (int i = 0; i < digit - 5; i++) {
                    roman += "C";
                }
            } else if (digit == 9) {
                roman += "CM";
            }
        } else if (place == 1) {
            if (digit <= 3) {
                for (int i = 0; i < digit; i++) {
                    roman += "X";
                }
            } else if (digit == 4) {
                roman += "XL";
            } else if (digit == 5) {
                roman = "L";
            } else if (digit <= 8) {
                roman += "L";
                for (int i = 0; i < digit - 5; i++) {
                    roman += "X";
                }
            } else if (digit == 9) {
                roman += "XC";
            }
        } else if (place == 0) {
            if (digit <= 3) {
                for (int i = 0; i < digit; i++) {
                    roman += "I";
                }
            } else if (digit == 4) {
                roman += "IV";
            } else if (digit == 5) {
                roman = "V";
            } else if (digit <= 8) {
                roman += "V";
                for (int i = 0; i < digit - 5; i++) {
                    roman += "I";
                }
            } else if (digit == 9) {
                roman += "IX";
            }
        }
        return roman;
    }
};