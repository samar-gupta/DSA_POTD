class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) {
        // code here
        if(!root)return NULL;
        if(root -> left && !root -> right)
        {
            return RemoveHalfNodes(root -> left);
        }
        if(!root -> left && root -> right)
        {
            return RemoveHalfNodes(root -> right);
        }
        root -> left = RemoveHalfNodes(root -> left);
        root -> right = RemoveHalfNodes(root -> right);
        return root;
    }
};
