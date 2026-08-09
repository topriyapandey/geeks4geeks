class Solution {
  public:

    static bool cmp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0])
            return a[2] < b[2];   // smaller index first

        return a[0] < b[0];       // smaller finish time first
    }

    vector<int> maxMeetings(vector<int>& s, vector<int>& f) {

        int n = s.size();

        vector<vector<int>> meetings;

        for(int i = 0; i < n; i++) {
            meetings.push_back({f[i], s[i], i + 1});
        }

        sort(meetings.begin(), meetings.end(), cmp);

        vector<int> ans;

        int lastFinish = -1;

        for(int i = 0; i < n; i++) {

            if(meetings[i][1] > lastFinish) {
                ans.push_back(meetings[i][2]);
                lastFinish = meetings[i][0];
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};