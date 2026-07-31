class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        vector<int> ans;
        queue<int> q;

        for (int i = 0; i < arr.size(); i++) {

            if (arr[i] < 0)
                q.push(i);

            while (!q.empty() && q.front() <= i - k)
                q.pop();

            if (i >= k - 1) {
                if (q.empty())
                    ans.push_back(0);
                else
                    ans.push_back(arr[q.front()]);
            }
        }

        return ans;
    }
};