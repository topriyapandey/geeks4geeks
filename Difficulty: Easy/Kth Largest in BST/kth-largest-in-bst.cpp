class Solution {
  public:
    void reverseInorder(Node* root, int &k, int &ans) {
        if (root == NULL)
            return;

        reverseInorder(root->right, k, ans);

        k--;
        if (k == 0) {
            ans = root->data;
            return;
        }

        reverseInorder(root->left, k, ans);
    }

    int kthLargest(Node *root, int k) {
        int ans = -1;
        reverseInorder(root, k, ans);
        return ans;
    }
};