class Solution {
public:
    long long nPr(int n, int r) {
        long long result = 1;

        for (int i = 0; i < r; i++) {
            result *= (n - i);
        }

        return result;
    }
};