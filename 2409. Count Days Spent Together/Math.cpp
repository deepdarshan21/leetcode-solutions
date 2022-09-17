#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(1) Space: O(1)
   Status: Accepted
   Runtime: 2 ms faster than: 65%
   Memory Usage: 5.9 MB less than: 95%
   Remarks:
*/

class Solution {
   public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> m = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int ams, ads, ame, ade, bms, bds, bme, bde;
        ams = stoi(arriveAlice.substr(0, 2));
        ads = stoi(arriveAlice.substr(3, 2));
        ame = stoi(leaveAlice.substr(0, 2));
        ade = stoi(leaveAlice.substr(3, 2));
        bms = stoi(arriveBob.substr(0, 2));
        bds = stoi(arriveBob.substr(3, 2));
        bme = stoi(leaveBob.substr(0, 2));
        bde = stoi(leaveBob.substr(3, 2));
        int start, end, res = 0;
        if (ams > bme || bms > ame) {
            // cout<<0<<endl;
            return 0;
        } else {
            if (ame == bme) {
                end = min(ade, bde);
                if (ams == bms) {
                    start = max(ads, bds);
                    if (ams == ame) {
                        res = end - start + 1;
                        if (res < 0) return 0;
                        return res;
                    }
                    res += m[ams - 1] - start + 1;
                    for (int i = ams + 1; i < ame; i++) res += m[i - 1];
                    res += end;
                    if (res < 0) return 0;
                    return res;
                }
                if (ams > bms) {
                    start = ads;
                    if (ams == ame) {
                        res = end - start + 1;
                        if (res < 0) return 0;
                        return res;
                    }
                    res += m[ams - 1] - start + 1;
                    cout << res << endl;
                    for (int i = ams + 1; i < ame; i++) res += m[i - 1];
                    // cout<<res<<endl;
                    res += end;
                    cout << res << endl;
                    if (res < 0) return 0;
                    return res;
                }
                if (bms > ams) {
                    start = bds;
                    if (bms == ame) {
                        res = end - start + 1;
                        if (res < 0) return 0;
                        return res;
                    }
                    res += m[bms - 1] - start + 1;
                    for (int i = bms + 1; i < ame; i++) res += m[i - 1];
                    res += end;
                    if (res < 0) return 0;
                    return res;
                }
            }
            if (ame < bme) {
                end = ade;
                if (ams == bms) {
                    start = max(ads, bds);
                    if (ams == ame) {
                        res = end - start + 1;
                        if (res < 0) return 0;
                        return res;
                    }
                    res += m[ams - 1] - start + 1;
                    for (int i = ams + 1; i < ame; i++) res += m[i - 1];
                    res += end;
                    if (res < 0) return 0;
                    return res;
                }
                if (ams > bms) {
                    start = ads;
                    if (ams == ame) {
                        res = end - start + 1;
                        if (res < 0) return 0;
                        return res;
                    }
                    res += m[ams - 1] - start + 1;
                    for (int i = ams + 1; i < ame; i++) res += m[i - 1];
                    res += end;
                    if (res < 0) return 0;
                    return res;
                }
                if (bms > ams) {
                    start = bds;
                    if (bms == ame) {
                        res = end - start + 1;
                        if (res < 0) return 0;
                        return res;
                    }
                    res += m[bms - 1] - start + 1;
                    for (int i = bms + 1; i < ame; i++) res += m[i - 1];
                    res += end;
                    if (res < 0) return 0;
                    return res;
                }
            }
            if (ame > bme) {
                end = bde;
                if (ams == bms) {
                    start = max(ads, bds);
                    if (ams == bme) {
                        res = end - start + 1;
                        if (res < 0) return 0;
                        return res;
                    }
                    res += m[ams - 1] - start + 1;
                    for (int i = ams + 1; i < bme; i++) res += m[i - 1];
                    res += end;
                    if (res < 0) return 0;
                    return res;
                }
                if (ams > bms) {
                    start = ads;
                    if (ams == bme) {
                        res = end - start + 1;
                        if (res < 0) return 0;
                        return res;
                    }
                    res += m[ams - 1] - start + 1;
                    for (int i = ams + 1; i < bme; i++) res += m[i - 1];
                    res += end;
                    if (res < 0) return 0;
                    return res;
                }
                if (bms > ams) {
                    start = bds;
                    if (bms == bme) {
                        res = end - start + 1;
                        if (res < 0) return 0;
                        return res;
                    }
                    res += m[bms - 1] - start + 1;
                    for (int i = bms + 1; i < bme; i++) res += m[i - 1];
                    res += end;
                    if (res < 0) return 0;
                    return res;
                }
            }
        }
        return res;
    }
};