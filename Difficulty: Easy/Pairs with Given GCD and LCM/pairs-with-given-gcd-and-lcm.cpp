class Solution {
public:
    int pairCount(int x, int y) {
        if (y % x != 0) {
            return 0;
        }

        int count = 0;

        for (int a = x; a <= y; a += x) {
            int b = (x * y) / a;

            if (__gcd(a, b) == x && (a * b) / __gcd(a, b) == y) {
                count++;
            }
        }

        return count;
    }
};