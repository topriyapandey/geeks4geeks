#include <cmath>
#include <algorithm>
#include <climits>

class Solution {
private:
    int minDiff = INT_MAX;
    Node* prev = nullptr;

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        if (prev != nullptr) {
            minDiff = std::min(minDiff, root->data - prev->data);
        }
        prev = root;
        inorder(root->right);
    }

public:
    int absDiff(Node* root) {
        minDiff = INT_MAX;
        prev = nullptr;
        inorder(root);
        return minDiff;
    }
};