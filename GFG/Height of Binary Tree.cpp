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
