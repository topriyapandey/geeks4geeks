#include <string>
#include <vector>
#include <algorithm>

class Solution {
private:
    bool isSubsequence(const std::string& word, const std::string& s) {
        int i = 0, j = 0;
        int n = word.length(), m = s.length();
        while (i < n && j < m) {
            if (word[i] == s[j]) {
                i++;
            }
            j++;
        }
        return i == n;
    }

public:
    std::string findLongestWord(std::string s, std::vector<std::string>& d) {
        std::sort(d.begin(), d.end(), [](const std::string& a, const std::string& b) {
            if (a.length() != b.length()) {
                return a.length() > b.length();
            }
            return a < b;
        });

        for (const std::string& word : d) {
            if (isSubsequence(word, s)) {
                return word;
            }
        }

        return "";
    }
};