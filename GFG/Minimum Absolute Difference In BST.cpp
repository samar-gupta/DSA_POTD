//Approach :
class Solution {
  public:
    long long prev = -1;
    long long minDiff = 1e18;

    void inorder(Node* root) {
        if (!root) return;

        inorder(root->left);

        if (prev != -1) {
            long long diff = root->data - prev;
            if (diff < minDiff) minDiff = diff;
        }
        prev = root->data;

        inorder(root->right);
    }

    int absDiff(Node *root) {
        prev = -1;
        minDiff = 1e18;
        inorder(root);
        return (int)minDiff;
    }
};



//old
class Solution
{
    public:
    int ans=INT_MAX;
    
    void solve(Node* root, int&last){
        if(!root) return;
        
        solve(root->left, last);
        if(last!=-1){
            ans=min(ans, root->data - last);
        }
        last=root->data;
        solve(root->right, last);
    }
    
    int absolute_diff(Node *root)
    {
        //Your code here
        int last=-1;
        solve(root, last);
        
        return ans;
    }
};
