class Solution {
  public:
    // Initialize a pointer to store the previous node in DLL
    Node* prev = nullptr;
    
    // Helper function to perform inorder traversal and convert the BT to DLL
    void convertToDLL(Node* root, Node*& head) {
        // Base case
        if (root == NULL) {
            return;
        }

        // Recursively convert the left subtree
        convertToDLL(root->left, head);

        // Now, process the current node
        if (prev == NULL) {
            // This means this is the leftmost node, which will be the head of the DLL
            head = root;
        } else {
            // Link the current node with the previous node in DLL
            root->left = prev;  // Left acts as 'previous' in DLL
            prev->right = root;  // Right acts as 'next' in DLL
        }

        // Mark this node as the previous node before moving to the right subtree
        prev = root;

        // Recursively convert the right subtree
        convertToDLL(root->right, head);
    }
    
    // Main function to convert Binary Tree to Doubly Linked List
    Node* bToDLL(Node* root) {
        // Pointer to store the head of the DLL
        Node* head = nullptr;

        // Call the helper function to start conversion from root
        convertToDLL(root, head);

        // Return the head of the converted DLL
        return head;
    }
};
