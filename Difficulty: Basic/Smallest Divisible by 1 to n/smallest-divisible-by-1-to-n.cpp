class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long getSmallestDivNum(int n) {
        long long ans = 1;

        for (int i = 1; i <= n; i++) {
            ans = (ans / gcd(ans, i)) * i;
        }

        return ans;
    }
};