class Solution {
public:
    long long kthDigit(int a, int b, int k) {
        long long num = pow(a, b);

        for (int i = 1; i < k; i++) {
            num /= 10;
        }

        return num % 10;
    }
};