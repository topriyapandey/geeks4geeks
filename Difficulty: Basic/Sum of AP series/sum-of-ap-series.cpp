class Solution {
public:
    long sumOfAP(int n, int a, int d) {
        return (long)n * (2 * a + (n - 1) * d) / 2;
    }
};