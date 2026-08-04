class Solution {
public:
    int findCeil(Node* root, int x) {
        int ans = -1;

        while (root != NULL) {
            if (root->data == x)
                return root->data;

            if (root->data < x) {
                root = root->right;
            } else {
                ans = root->data;
                root = root->left;
            }
        }

        return ans;
    }
};