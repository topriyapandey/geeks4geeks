#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int solve(int n, std::string s) {
        std::unordered_set<char> occupied;
        std::unordered_set<char> leftWithoutComp;
        int unassigned = 0;

        for (char c : s) {
            if (occupied.count(c)) {
                occupied.erase(c);
            } else if (leftWithoutComp.count(c)) {
                leftWithoutComp.erase(c);
            } else {
                if (occupied.size() < n) {
                    occupied.insert(c);
                } else {
                    leftWithoutComp.insert(c);
                    unassigned++;
                }
            }
        }

        return unassigned;
    }
};