class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
        // code here
        if(!root) return;
        
        Node * temp = root->left;    //swap(node->left, node->right);
        root->left = root->right;
        root->right = temp;
        
        mirror(root->left);
        mirror(root->right);
    }
};
