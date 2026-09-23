class Solution {
public:
    long long formPyramid(vector<int>& arr) {
        int n = arr.size();

        vector<int> left(n), right(n);

        left[0] = 1;
        for (int i = 1; i < n; i++) {
            left[i] = min(arr[i], left[i - 1] + 1);
        }

        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(arr[i], right[i + 1] + 1);
        }

        long long sum = 0;
        long long best = 0;

        for (int i = 0; i < n; i++) {
            int height = min(left[i], right[i]);

            sum += height;
            best = max(best, (long long)height);
        }

        long long pyramidSum = 0;

        for (int i = 1; i <= best; i++) {
            pyramidSum += i;
        }

        pyramidSum = 2 * pyramidSum - best;

        long long total = 0;
        for (int x : arr) {
            total += x;
        }

        return total - pyramidSum;
    }
};