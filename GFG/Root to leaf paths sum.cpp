class Solution {
  public:
    int solve(Node* root, int currSum){
        if(root==NULL){
            return 0;
        }
        currSum = 10*currSum + root->data;
        if(root->left==NULL && root->right==NULL){
            return currSum;
        }
        
        int leftSum = solve(root->left,currSum);
        int rightSum = solve(root->right,currSum);
        return leftSum+rightSum;
    }
  
    int treePathsSum(Node *root) {
        // code here.
        return solve(root, 0);
    }
};
