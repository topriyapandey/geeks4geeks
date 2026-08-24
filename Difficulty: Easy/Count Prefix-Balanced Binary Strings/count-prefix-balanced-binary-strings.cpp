class Solution {
public:
    int prefixStrings(int n) {
        const long long MOD = 1000000007;

        long long fact2n = 1;
        long long factn = 1;
        long long factn1 = 1;

        for (int i = 1; i <= 2 * n; i++) {
            fact2n = fact2n * i % MOD;
        }

        for (int i = 1; i <= n; i++) {
            factn = factn * i % MOD;
        }

        for (int i = 1; i <= n + 1; i++) {
            factn1 = factn1 * i % MOD;
        }

        long long invFactN = 1;
        long long invFactN1 = 1;

        long long a = factn;
        long long b = MOD - 2;

        while (b) {
            if (b & 1)
                invFactN = invFactN * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }

        a = factn1;
        b = MOD - 2;

        while (b) {
            if (b & 1)
                invFactN1 = invFactN1 * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }

        long long result = fact2n;
        result = result * invFactN % MOD;
        result = result * invFactN1 % MOD;

        return result;
    }
};