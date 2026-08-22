class Solution {
public:
    Node* findLCA(Node* root, int p, int q) {
        if (root == NULL)
            return NULL;

        if (root->data == p || root->data == q)
            return root;

        Node* left = findLCA(root->left, p, q);
        Node* right = findLCA(root->right, p, q);

        if (left != NULL && right != NULL)
            return root;

        return left != NULL ? left : right;
    }

    bool findPath(Node* root, int target, string& path) {
        if (root == NULL)
            return false;

        if (root->data == target)
            return true;

        path.push_back('L');

        if (findPath(root->left, target, path))
            return true;

        path.pop_back();

        path.push_back('R');

        if (findPath(root->right, target, path))
            return true;

        path.pop_back();

        return false;
    }

    int numberOfTurns(Node* root, int first, int second) {
        Node* lca = findLCA(root, first, second);

        if (lca == NULL)
            return -1;

        string path1, path2;

        findPath(lca, first, path1);
        findPath(lca, second, path2);

        reverse(path1.begin(), path1.end());

        string path = path1 + path2;

        int turns = 0;

        for (int i = 1; i < path.length(); i++) {
            if (path[i] != path[i - 1])
                turns++;
        }

        return turns == 0 ? -1 : turns;
    }
};