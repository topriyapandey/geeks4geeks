#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isDigitSumPalindrome(int n) {
        int sum = 0;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        int original = sum;
        int reversed = 0;

        while (sum > 0) {
            reversed = reversed * 10 + sum % 10;
            sum /= 10;
        }

        return original == reversed;
    }
};