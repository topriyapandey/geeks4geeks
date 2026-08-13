class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) {
        vector<int> ans;

        long long d = 1LL * b * b - 4LL * a * c;

        if (d < 0) {
            ans.push_back(-1);
            return ans;
        }

        double sqrtD = sqrt(d);

        int r1 = floor((-b + sqrtD) / (2.0 * a));
        int r2 = floor((-b - sqrtD) / (2.0 * a));

        if (r1 < r2) swap(r1, r2);

        ans.push_back(r1);
        ans.push_back(r2);

        return ans;
    }
};