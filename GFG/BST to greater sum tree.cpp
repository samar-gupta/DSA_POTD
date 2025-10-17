//Approach-1 :
class Solution {
  public:
    int sum=0;
    void transformTree(Node *root) {
        // code here
        if(!root){
            return;
        }
        transformTree(root->right);
        sum+=root->data;
        root->data=sum-root->data;
        transformTree(root->left);
        
        return;
    }
};


//Approach-2 :
class Solution {
  public:
    void solve(Node* root, int &totSum){
        if(!root) return;
        solve(root->left,totSum);
        totSum-= root->data;
        root->data=totSum;
        solve(root->right,totSum);
    }
    void findSum(Node* root, int &totSum){
        if(!root) return;
        findSum(root->left,totSum);
        totSum+=root->data;
        findSum(root->right,totSum);
    }
    
    void transformTree(Node *root) {
        // code here
        int totSum = 0;
        findSum(root,totSum);
        solve(root,totSum);
    }
};
