class Solution {
public:
    int cubeRoot(int n) {
        int low = 1, high = n;
        int ans = 1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long cube = mid * mid * mid;

            if (cube <= n) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};