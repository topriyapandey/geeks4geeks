class Solution {
public:
    void findLeaves(Node* root, int level, vector<int>& costs) {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL) {
            costs.push_back(level);
            return;
        }

        findLeaves(root->left, level + 1, costs);
        findLeaves(root->right, level + 1, costs);
    }

    int getCount(Node* root, int k) {
        vector<int> costs;

        findLeaves(root, 1, costs);

        sort(costs.begin(), costs.end());

        int count = 0;

        for (int cost : costs) {
            if (k < cost)
                break;

            k -= cost;
            count++;
        }

        return count;
    }
};