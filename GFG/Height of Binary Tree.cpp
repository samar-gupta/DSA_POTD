//(updated)
class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        // code here
        if (node == NULL)
            return -1;
        return 1 + max(height(node->left), height(node->right));
    }
};


//(old version)
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        
        if(node == 0) return 0;
        
        int l = height(node->left);
        int r = height(node->right);
        
        return 1 + max(l, r);
    }
};
