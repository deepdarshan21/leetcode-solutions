#include <bits/stdc++.h>
using namespace std;

/*
   Approach: upper_bound stl


   Edge Cases:

   Time Complexity: O(log(n)) Space: O(1)
   Status: Accepted
   Runtime: 304 ms faster than: 89.83%
   Memory Usage: 129.3 MB less than: 60.65%
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
        string res = "";
        auto itr = upper_bound(mp[key].begin(), mp[key].end(), timestamp, [](int val, pair<int, string> p) {
            return val < p.first;
        });
        if (itr != mp[key].begin()) {
            res = (--itr)->second;
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