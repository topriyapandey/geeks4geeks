class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {

        long long windowSum = 0;

        for(int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        long long maxSum = windowSum;

        for(int i = k; i < arr.size(); i++) {
            windowSum += arr[i] - arr[i-k];
            maxSum = max(maxSum, windowSum);
        }

        return maxSum;
    }
};