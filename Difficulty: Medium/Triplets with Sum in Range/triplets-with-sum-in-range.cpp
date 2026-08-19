class Solution {
public:
    long long countTriplets(vector<int>& arr, int l, int r) {
        sort(arr.begin(), arr.end());

        auto countLessEqual = [&](long long x) {
            long long count = 0;
            int n = arr.size();

            for (int i = 0; i < n - 2; i++) {
                int left = i + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)arr[i] + arr[left] + arr[right];

                    if (sum <= x) {
                        count += right - left;
                        left++;
                    } else {
                        right--;
                    }
                }
            }

            return count;
        };

        return countLessEqual(r) - countLessEqual(l - 1);
    }
};