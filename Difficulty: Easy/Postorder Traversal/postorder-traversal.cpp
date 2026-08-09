class Solution {
public:
    void dfs(Node* root, vector<int>& ans) {
        if (!root) return;

        dfs(root->left, ans);
        dfs(root->right, ans);
        ans.push_back(root->data);
    }

    vector<int> postOrder(Node* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};