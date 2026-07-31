class Solution {
public:
    int findMaxFork(Node* root, int k) {
        int ans = -1;

        while (root != NULL) {
            if (root->data == k)
                return root->data;

            if (root->data > k) {
                root = root->left;
            } else {
                ans = root->data;
                root = root->right;
            }
        }

        return ans;
    }
};