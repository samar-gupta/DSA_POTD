//updated
class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        int ans = -1;
        Node* curr = root;
        
        while(curr){
            
            if(curr->data <= k){
                ans = curr->data;
                curr = curr->right;
            }else{
                curr = curr->left;
            }
        }
        
        return ans;
    }
};


//old
class Solution {
  public:
    int ans=INT_MIN;
    
    void solve(Node* root, int n){
        if(root==NULL) return;
        
        if(root->key <= n){
            ans=max(ans, root->key);
            solve(root->right, n);
        }
        else{
            solve(root->left, n);
        }
        
        return;
    }
    int findMaxForN(Node* root, int n) {
        // code here
        solve(root, n);
        if(ans==INT_MIN){
            ans=-1;
        }
        
        return ans;
        
    }
};
