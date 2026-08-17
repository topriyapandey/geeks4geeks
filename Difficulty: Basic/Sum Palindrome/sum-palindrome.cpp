#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int n) {
        int original = n;
        int reversed = 0;

        while (n > 0) {
            reversed = reversed * 10 + n % 10;
            n /= 10;
        }

        return original == reversed;
    }

    int reverseNumber(int n) {
        int reversed = 0;

        while (n > 0) {
            reversed = reversed * 10 + n % 10;
            n /= 10;
        }

        return reversed;
    }

    int isSumPalindrome(int n) {
        if (isPalindrome(n))
            return n;

        for (int i = 0; i < 5; i++) {
            n = n + reverseNumber(n);

            if (isPalindrome(n))
                return n;
        }

        return -1;
    }
};