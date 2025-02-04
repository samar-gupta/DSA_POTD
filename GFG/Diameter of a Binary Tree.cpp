class Solution {
  public:
    
    int ans = 0;
    
    int calc(Node* root){
        if(root==NULL){
           return 0;
        }
        int left = calc(root->left);
        int right = calc(root->right);
        ans = max(ans, left+right);
        return max(left, right) + 1;
    }
   
    int diameter(Node* root) {
        // Your code here
        calc(root);
        return ans;
    }
};
