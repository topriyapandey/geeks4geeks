class Solution {
public:
    int totalJumps(vector<int>& arr, int x, int y) {
        int ans = 0;

        for (int h : arr) {
            if (h <= x) {
                ans++;
            } else {
                ans += (h - x + (x - y) - 1) / (x - y) + 1;
            }
        }

        return ans;
    }
};