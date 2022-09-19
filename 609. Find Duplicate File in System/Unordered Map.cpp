#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Unorded Map


   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 241 ms faster than: 22.87%
   Memory Usage: 44.6 MB less than: 32.06%
   Remarks:
*/

class Solution {
   public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> files;
        vector<vector<string>> result;

        for (auto path : paths) {
            stringstream ss(path);
            string root;
            string s;
            getline(ss, root, ' ');
            while (getline(ss, s, ' ')) {
                string fileName = root + '/' + s.substr(0, s.find('('));
                string fileContent = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
                files[fileContent].push_back(fileName);
            }
        }

        for (auto file : files) {
            if (file.second.size() > 1)
                result.push_back(file.second);
        }

        return result;
    }
};