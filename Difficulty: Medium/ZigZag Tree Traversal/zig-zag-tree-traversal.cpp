class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        queue<Node*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                int index;
                if (leftToRight)
                    index = i;
                else
                    index = size - 1 - i;

                level[index] = curr->data;

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            for (int x : level)
                ans.push_back(x);

            leftToRight = !leftToRight;
        }

        return ans;
    }
};