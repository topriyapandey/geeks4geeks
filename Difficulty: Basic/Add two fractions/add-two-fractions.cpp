#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> addFraction(int num1, int den1, int num2, int den2) {
        int numerator = num1 * den2 + num2 * den1;
        int denominator = den1 * den2;

        int g = gcd(numerator, denominator);

        return {numerator / g, denominator / g};
    }
};