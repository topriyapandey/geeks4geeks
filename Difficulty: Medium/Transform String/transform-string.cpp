class Solution {
public:
    int transform(string s1, string s2) {
        if (s1.length() != s2.length())
            return -1;

        int n = s1.length();

        string a = s1;
        string b = s2;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a != b)
            return -1;

        int i = n - 1;
        int j = n - 1;
        int count = 0;

        while (i >= 0) {
            if (s1[i] == s2[j]) {
                i--;
                j--;
            } else {
                count++;
                i--;
            }
        }

        return count;
    }
};