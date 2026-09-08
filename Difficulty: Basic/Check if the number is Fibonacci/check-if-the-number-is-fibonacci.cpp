class Solution {
public:
    bool isFibonacci(int n) {
        int a = 0, b = 1;

        while (b < n) {
            int c = a + b;
            a = b;
            b = c;
        }

        return n == 0 || b == n;
    }
};