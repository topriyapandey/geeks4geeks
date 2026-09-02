#include <string>

class Solution {
public:
    int countDigits(int n) {
        return std::to_string(n).length();
    }
};