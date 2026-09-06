class Solution {
public:
    int sumOfGP(int n, int a, int r) {
        int sum = 0;
        int term = a;

        for (int i = 0; i < n; i++) {
            sum += term;
            term *= r;
        }

        return sum;
    }
};