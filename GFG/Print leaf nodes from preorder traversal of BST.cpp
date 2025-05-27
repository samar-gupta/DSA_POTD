// Approach: Use a stack to simulate BST insertion from preorder and detect leaf nodes based on how many ancestors are popped. If two or more nodes are popped, the previous node is a leaf.
// Time Complexity: O(n) – each element is pushed and popped at most once.
// Space Complexity: O(n) – stack can grow up to n in worst case.
class Solution {
public:
    vector<int> leafNodes(vector<int>& preorder) {
        stack<int>  st;     // Stack to simulate the path of nodes in BST
        vector<int> result; // To store the final leaf nodes

        for (int i = 0; i < preorder.size(); i++) {
            int count = 0;
            int curr  = preorder[i]; // Current node in preorder

            // Pop until we find a node greater than current, simulating right child path
            while (!st.empty() && curr > st.top()) {
                st.pop();
                count++;
            }

            // If two or more nodes are popped, then the previous node is a leaf
            if (count >= 2) {
                result.push_back(preorder[i - 1]);
            }

            // Push current node to stack
            st.push(curr);
        }

        // Last node is always a leaf in preorder traversal
        result.push_back(preorder.back());

        return result;
    }
};
