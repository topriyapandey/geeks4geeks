class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int x) {
        vector<long long> nums;

        long long total = s;

        if (s <= x)
            nums.push_back(s);

        for (int v : arr) {
            long long cur = total + v;

            if (cur <= x)
                nums.push_back(cur);

            total += cur;

            if (total > 2LL * x)
                break;
        }

        int n = nums.size();
        int mid = n / 2;

        vector<long long> left, right;

        for (int mask = 0; mask < (1 << mid); mask++) {
            long long sum = 0;
            for (int i = 0; i < mid; i++) {
                if (mask & (1 << i))
                    sum += nums[i];
            }
            if (sum <= x)
                left.push_back(sum);
        }

        int rsz = n - mid;
        for (int mask = 0; mask < (1 << rsz); mask++) {
            long long sum = 0;
            for (int i = 0; i < rsz; i++) {
                if (mask & (1 << i))
                    sum += nums[mid + i];
            }
            if (sum <= x)
                right.push_back(sum);
        }

        sort(right.begin(), right.end());

        for (long long a : left) {
            long long need = x - a;
            if (binary_search(right.begin(), right.end(), need))
                return true;
        }

        return false;
    }
};