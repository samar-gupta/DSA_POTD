class Solution {
  public:
    bool isSame(Node* a, Node* b) {
        if(a == NULL && b == NULL)
            return true;
        
        if(a == NULL || b == NULL)
            return false;
        
        if(a->data != b->data)
            return false;
        
        return isSame(a->left, b->left) &&
               isSame(a->right, b->right);
    }
    
    bool isSubTree(Node *root1, Node *root2) {
        // code here
        if(root2 == NULL)
            return true;
        
        if(root1 == NULL)
            return false;
        
        if(isSame(root1, root2))
            return true;
        
        return isSubTree(root1->left, root2) ||
               isSubTree(root1->right, root2);
    }
};
