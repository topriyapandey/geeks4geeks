class Solution {
public:
    string isAutomorphic(int n) {
        int square = n * n;
        int temp = n;

        while (temp > 0) {
            if (square % 10 != temp % 10) {
                return "Not Automorphic";
            }

            square /= 10;
            temp /= 10;
        }

        return "Automorphic";
    }
};