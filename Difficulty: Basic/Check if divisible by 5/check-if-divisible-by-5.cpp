class Solution {
public:
    bool divisibleBy5(string N) {
        return N.back() == '0' || N.back() == '5';
    }
};