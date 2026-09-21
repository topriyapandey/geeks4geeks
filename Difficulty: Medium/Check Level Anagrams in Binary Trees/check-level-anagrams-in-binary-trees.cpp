#include <queue>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool areAnagrams(Node* root1, Node* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;

        std::queue<Node*> q1, q2;
        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {
            int n1 = q1.size();
            int n2 = q2.size();

            if (n1 != n2) return false;

            std::unordered_map<int, int> freq;

            for (int i = 0; i < n1; ++i) {
                Node* curr1 = q1.front();
                q1.pop();
                freq[curr1->data]++;

                if (curr1->left) q1.push(curr1->left);
                if (curr1->right) q1.push(curr1->right);

                Node* curr2 = q2.front();
                q2.pop();
                freq[curr2->data]--;

                if (curr2->left) q2.push(curr2->left);
                if (curr2->right) q2.push(curr2->right);
            }

            for (auto& pair : freq) {
                if (pair.second != 0) return false;
            }
        }

        return q1.empty() && q2.empty();
    }
};