class Solution {
public:
    long long sumOfDivisors(int n) {
        long long ans = 0;

        for (int i = 1; i <= n; i++) {
            ans += 1LL * i * (n / i);
        }

        return ans;
    }
};