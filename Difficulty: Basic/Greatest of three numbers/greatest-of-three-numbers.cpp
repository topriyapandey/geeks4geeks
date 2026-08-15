#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int greatestOfThree(int a, int b, int c) {
        if (a >= b && a >= c)
            return a;
        else if (b >= a && b >= c)
            return b;
        else
            return c;
    }
};

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    Solution ob;
    cout << ob.greatestOfThree(a, b, c);

    return 0;
}