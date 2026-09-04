#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distance(int x1, int y1, int x2, int y2) {
        long long dx = x2 - x1;
        long long dy = y2 - y1;

        return round(sqrt(dx * dx + dy * dy));
    }
};