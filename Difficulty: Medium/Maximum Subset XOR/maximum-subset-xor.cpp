class Solution {
public:
    int maxSubsetXOR(vector<int> &arr) {
        int n = arr.size();
        int index = 0;

        for (int bit = 31; bit >= 0; bit--) {

            int maxIndex = -1;
            int maxEle = -1;

            for (int i = index; i < n; i++) {
                if ((arr[i] & (1 << bit)) && arr[i] > maxEle) {
                    maxEle = arr[i];
                    maxIndex = i;
                }
            }

            if (maxIndex == -1)
                continue;

            swap(arr[index], arr[maxIndex]);

            for (int i = 0; i < n; i++) {
                if (i != index && (arr[i] & (1 << bit))) {
                    arr[i] ^= arr[index];
                }
            }

            index++;
        }

        int ans = 0;
        for (int x : arr)
            ans ^= x;

        return ans;
    }
};