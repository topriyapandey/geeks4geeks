class Solution {
public:
    int nthPosition(int n) {
        int ans = 1;

        while (ans * 2 <= n) {
            ans *= 2;
        }

        return ans;
    }
};