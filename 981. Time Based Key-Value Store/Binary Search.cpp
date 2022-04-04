#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search


   Edge Cases:

   Time Complexity: O(log(n)) Space: O(1)
   Status: Accepted
   Runtime: 404 ms faster than: 69.92%
   Memory Usage: 128.5 MB less than: 66.55%
   Remarks:
*/

class TimeMap {
   private:
    using timeVal = pair<int, string>;
    unordered_map<string, vector<timeVal>> mp;

   public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        int low = 0, mid, high = mp[key].size() - 1;
        string res = "";
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (mp[key][mid].first == timestamp) {
                res = mp[key][mid].second;
                return res;
            } else {
                if (mp[key][mid].first < timestamp) {
                    res = mp[key][mid].second;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 **/