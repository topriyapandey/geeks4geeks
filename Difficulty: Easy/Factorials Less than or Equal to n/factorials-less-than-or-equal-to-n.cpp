#include <vector>

class Solution {
public:
    std::vector<long long> factorialNumbers(long long n) {
        std::vector<long long> result;
        long long fact = 1;
        long long i = 1;

        while (fact <= n) {
            result.push_back(fact);
            i++;
            if (n / i < fact) {
                break;
            }
            fact *= i;
        }

        return result;
    }
};