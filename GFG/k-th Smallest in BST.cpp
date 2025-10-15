//Approach-1 : 
//Since inorder traversal of a BST gives us ascending order traversal of a tree, 
//so we used inorder traversal and thus decreased K in that order
class Solution {
  public:
    void inorder(Node* root, int &k, int &ans)
    {
        if(root == NULL)
            return;
    
        inorder(root->left, k, ans);
        k--;
        
        if(k == 0) {
            ans = root->data;
            return;
        }
        
        inorder(root->right, k, ans);
    }

    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        // code here
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};
