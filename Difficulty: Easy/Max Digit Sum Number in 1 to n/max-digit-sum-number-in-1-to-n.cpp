class Solution {
public:
    int digitSum(int n) {
        int sum = 0;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int findMax(int n) {
        int ans = n;
        int bestSum = digitSum(n);

        for (int power = 10; power <= n; power *= 10) {
            int candidate = (n / power - 1) * power + (power - 1);

            if (candidate < 1) continue;

            int sum = digitSum(candidate);

            if (sum > bestSum || (sum == bestSum && candidate > ans)) {
                bestSum = sum;
                ans = candidate;
            }

            if (power > n / 10) break;
        }

        return ans;
    }
};