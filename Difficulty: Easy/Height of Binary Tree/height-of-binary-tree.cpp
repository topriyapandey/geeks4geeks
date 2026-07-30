class Solution {
  public:
    int height(Node *node) {
        if (node == NULL)
            return -1;

        int left = height(node->left);
        int right = height(node->right);

        return max(left, right) + 1;
    }
};