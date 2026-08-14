class Solution {
  public:
    int countSquares(int n) {
        int root = sqrt(n);

        if (root * root == n)
            return root - 1;

        return root;
    }
};