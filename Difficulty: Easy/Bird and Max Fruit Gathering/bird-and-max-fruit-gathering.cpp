class Solution {
public:
    long long maxFruits(vector<int>& arr, int m) {
        int n = arr.size();

        if (m >= n) {
            long long total = 0;
            for (int x : arr) total += x;
            return total;
        }

        long long sum = 0, ans = 0;

        for (int i = 0; i < m; i++) {
            sum += arr[i];
        }

        ans = sum;

        for (int i = m; i < n + m; i++) {
            sum += arr[i % n];
            sum -= arr[(i - m) % n];
            ans = max(ans, sum);
        }

        return ans;
    }
};