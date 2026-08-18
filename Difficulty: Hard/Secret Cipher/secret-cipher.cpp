class Solution {
public:
    string compress(string s) {
        int n = s.size();

        const long long mod = 1000000007;
        const long long base = 31;

        vector<long long> hash(n + 1, 0);
        vector<long long> power(n + 1, 1);

        for (int i = 0; i < n; i++) {
            hash[i + 1] = (hash[i] * base + (s[i] - 'a' + 1)) % mod;
            power[i + 1] = (power[i] * base) % mod;
        }

        auto getHash = [&](int l, int r) {
            long long val = hash[r] - (hash[l] * power[r - l]) % mod;
            if (val < 0) val += mod;
            return val;
        };

        string ans;
        int len = n;

        while (len > 0) {
            if (len % 2 == 0) {
                int half = len / 2;

                if (getHash(0, half) == getHash(half, len)) {
                    ans.push_back('*');
                    len = half;
                    continue;
                }
            }

            ans.push_back(s[len - 1]);
            len--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};