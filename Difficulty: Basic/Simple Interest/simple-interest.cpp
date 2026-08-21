#include <iostream>
#include <iomanip>
using namespace std;

class Solution {
public:
    double simpleInterest(int p, int r, int t) {
        return (p * r * t) / 100.0;
    }
};

int main() {
    Solution ob;
    int p, r, t;
    cin >> p >> r >> t;
    cout << fixed << setprecision(2) << ob.simpleInterest(p, r, t);
    return 0;
}