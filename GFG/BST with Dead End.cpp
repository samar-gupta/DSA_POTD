// Approach: Perform DFS traversal and keep track of the min and max bounds where a node can be placed. At each leaf, if (max - min == 2) and root->data is exactly in the middle, it's a dead end (i.e., root->data - min == 1 and max - root->data == 1).
// Time Complexity: O(N), where N is the number of nodes in the BST. Each node is visited once.
// Space Complexity: O(H), where H is the height of the BST (O(log N) for balanced, O(N) for skewed) due to recursive call stack.
class Solution {
public:

    // Helper DFS function to detect dead ends in BST
    bool dfs(Node* root, int min, int max) {
        if (!root) {
            return 0; // base case: empty subtree cannot have dead end
        }

        // if it's a leaf node
        if (!root->left && !root->right) {
            // check if no number can be inserted at or below this leaf
            if (root->data - min == 1 && max - root->data == 1) {
                return 1; // dead end found
            } else {
                return 0; // not a dead end
            }
        }

        // recursively check in left and right subtrees
        return dfs(root->left, min, root->data) ||
               dfs(root->right, root->data, max);
    }

    bool isDeadEnd(Node* root) {
        // Start with min = 0 and max = INT_MAX for root
        return dfs(root, 0, INT_MAX);
    }
};
