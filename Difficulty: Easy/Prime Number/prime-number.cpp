class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;

        for (int i = 2; i * 1LL * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }
};