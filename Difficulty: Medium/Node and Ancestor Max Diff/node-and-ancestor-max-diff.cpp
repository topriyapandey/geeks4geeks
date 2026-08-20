class Solution {
public:
    int maxDiff(Node* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }

private:
    int solve(Node* root, int& ans) {
        if (root == NULL)
            return INT_MAX;

        if (root->left == NULL && root->right == NULL)
            return root->data;

        int leftMin = solve(root->left, ans);
        int rightMin = solve(root->right, ans);

        int childMin = min(leftMin, rightMin);

        ans = max(ans, root->data - childMin);

        return min(root->data, childMin);
    }
};