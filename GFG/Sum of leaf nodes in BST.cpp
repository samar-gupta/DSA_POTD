class Solution {
    public:     
        int sumOfLeafNodes(Node *root ){
            if(!root)
                return 0;
            
            if(!root->left && !root->right)
                return root->data;
            
            return sumOfLeafNodes(root->left) + sumOfLeafNodes(root->right);
        }
};
