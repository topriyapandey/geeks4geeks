#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int n, vector<int>& arr) {
        int result = arr[0];

        for (int i = 1; i < n; i++) {
            result = __gcd(result, arr[i]);
        }

        return result;
    }
};