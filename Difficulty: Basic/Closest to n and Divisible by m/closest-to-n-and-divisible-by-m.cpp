class Solution {
  public:
    int closestNumber(int n, int m) {
        int q = n / m;

        int n1 = m * q;
        int n2;

        if (n * m > 0)
            n2 = m * (q + 1);
        else
            n2 = m * (q - 1);

        if (abs(n - n1) < abs(n - n2))
            return n1;
        else if (abs(n - n1) > abs(n - n2))
            return n2;
        else
            return (abs(n1) > abs(n2)) ? n1 : n2;
    }
};