#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Failling in tesst case: "(((((*((*********((*(((((****"
*/

class Solution {
   public:
    bool checkValidString(string s) {
        bool checkValidString(string s) {
            unordered_map<char, int> mp;
            for (char x : s) {
                mp[x]++;
                // cout<<x<<" "<<mp['(']<<" "<<mp['*']<<endl;
                if (x == ')') {
                    if (mp['('] > 0)
                        mp['(']--;
                    else if (mp['*'] > 0)
                        mp['*']--;
                    else {
                        cout << "here" << endl;
                        return false;
                    }
                }
                cout << x << " " << mp['('] << " " << mp['*'] << endl;
            }
            cout << mp['('] << endl;
            if (mp['('] == 0) return true;
            cout << "check" << endl;
            if (mp['('] <= mp['*']) return true;
            return false;
        }
    }
};