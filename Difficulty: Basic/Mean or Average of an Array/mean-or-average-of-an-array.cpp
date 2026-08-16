#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMean(vector<int>& arr) {
        long long sum = 0;

        for (int x : arr) {
            sum += x;
        }

        return sum / arr.size();
    }
};