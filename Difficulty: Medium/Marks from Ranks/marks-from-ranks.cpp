class Solution {
public:
    vector<int> getMarks(vector<int>& l, vector<int>& r, vector<int>& rank) {
        int n = l.size();
        vector<long long> prefix(n);

        prefix[0] = r[0] - l[0] + 1;

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + (r[i] - l[i] + 1);
        }

        vector<int> ans;

        for (int x : rank) {
            int idx = lower_bound(prefix.begin(), prefix.end(), x) - prefix.begin();

            long long prev = idx == 0 ? 0 : prefix[idx - 1];

            ans.push_back(l[idx] + (x - prev - 1));
        }

        return ans;
    }
};