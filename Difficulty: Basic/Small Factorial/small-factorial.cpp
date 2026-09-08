class Solution {
public:
    long long find_fact(int n) {
        long long fact = 1;

        for (int i = 1; i <= n; i++) {
            fact *= i;
        }

        return fact;
    }
};