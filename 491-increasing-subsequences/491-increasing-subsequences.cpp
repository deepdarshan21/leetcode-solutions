class Solution {
public:
    set<vector<int>> ans;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        help(nums, 0, {});
        vector<vector<int>> ans1(ans.begin(), ans.end());
        return ans1;
    }
    void help(vector<int> nums, int start, vector<int> store) {
        for (int i = start; i < nums.size(); i++) {
            if (store.size() == 0) {
                store.push_back(nums[i]);
                help(nums, i + 1, store);
                store.pop_back();
            } else {
                if (nums[i] >= store[store.size() - 1]) {
                    store.push_back(nums[i]);
                    ans.insert(store);
                    help(nums, i + 1, store);
                    store.pop_back();
                }
            }
        }
    }
};