class Solution {
public:
    int sameMod(vector<int>& arr) {
        bool same = true;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] != arr[0]) {
                same = false;
                break;
            }
        }

        if (same) {
            return -1;
        }

        int g = 0;

        for (int i = 1; i < arr.size(); i++) {
            g = __gcd(g, abs(arr[i] - arr[0]));
        }

        int ans = 0;

        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                ans++;

                if (i != g / i) {
                    ans++;
                }
            }
        }

        return ans;
    }
};