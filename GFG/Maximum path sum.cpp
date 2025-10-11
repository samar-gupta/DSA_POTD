//Approach-1 : 
class Solution {
  public:
    int solve(Node *root,int &ans){
        if(root==nullptr) return 0;
        int left = max(0,solve(root->left,ans));
        int right = max(0,solve(root->right,ans));
        ans = max(ans,root->data+left+right);
        return  root->data + max(left,right);
    }
    
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        // code here
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};
