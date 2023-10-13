class Solution{
public:
    
    int ans = -1;
    
    int floor(Node* root, int x) {
        if(!root) {
            return ans;
        }
        else if(root->data == x) {
            ans = x;
            return ans;
        }
        else if(root->data < x) {
            ans = max(ans, root->data);
            floor(root->right, x);
            return ans;
        }
        else {
            floor(root->left, x);
            return ans;
        }
    }
};
