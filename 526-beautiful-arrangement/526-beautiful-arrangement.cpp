class Solution {
public:
    int count = 0;
    int countArrangement(int n) {
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back(i + 1);
        }
        help(arr, 0);
        return count;
    }
    void help(vector<int> arr, int curr) {
        // cout << "help " << arr[curr] << endl;
        if (curr == arr.size()) {
            count++;
        }
        for (int i = curr; i < arr.size(); i++) {
            swap(arr[i], arr[curr]);
            if (arr[curr] % (curr + 1) == 0 || (curr + 1) % arr[curr] == 0) {
                help(arr, curr + 1);
            }
            swap(arr[i], arr[curr]);
        }
    }
};