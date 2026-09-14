class Solution {
public:
    long long nthEvenFibonacci(int n) {
        long long a = 2, b = 8;

        if (n == 1)
            return a;

        for (int i = 2; i <= n; i++) {
            long long c = 4 * b + a;
            a = b;
            b = c;
        }

        return a;
    }
};