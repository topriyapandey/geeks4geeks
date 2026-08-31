class Solution {
public:
    int isPerfect(int N) {
        int original = N;
        int sum = 0;
        int fact[10] = {
            1, 1, 2, 6, 24,
            120, 720, 5040, 40320, 362880
        };

        while (N > 0) {
            int digit = N % 10;
            sum += fact[digit];
            N /= 10;
        }

        return (sum == original) ? 1 : 0;
    }
};