class Solution {
public:
    int termOfGP(int a, int b, int n) {
        int ratio = b / a;
        int ans = a;

        for (int i = 1; i < n; i++) {
            ans *= ratio;
        }

        return ans;
    }
};