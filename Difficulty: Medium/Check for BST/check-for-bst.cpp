class Solution {
public:
    bool solve(Node* root, long long mn, long long mx) {
        if (root == NULL)
            return true;

        if (root->data <= mn || root->data >= mx)
            return false;

        return solve(root->left, mn, root->data) &&
               solve(root->right, root->data, mx);
    }

    bool isBST(Node* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};