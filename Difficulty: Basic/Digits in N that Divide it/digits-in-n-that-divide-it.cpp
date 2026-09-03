class Solution {
public:
    int divisibleByDigits(string s) {
        int rem[10] = {0};

        for (char ch : s) {
            int digit = ch - '0';

            for (int d = 1; d <= 9; d++) {
                rem[d] = (rem[d] * 10 + digit) % d;
            }
        }

        int ans = 0;

        for (char ch : s) {
            int digit = ch - '0';

            if (digit != 0 && rem[digit] == 0) {
                ans++;
            }
        }

        return ans;
    }
};