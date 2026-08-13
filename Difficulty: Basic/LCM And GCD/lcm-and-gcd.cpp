class Solution {
  public:
  
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
  
    vector<int> lcmAndGcd(int a, int b) {
        int g = gcd(a, b);
        int l = (a * b) / g;
        
        return {l, g};
    }
};