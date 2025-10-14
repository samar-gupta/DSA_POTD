//Approach-1 :
class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        // code here
        if (!root) {
            return 0;
        }
        
        if (root->data >= l && root->data <= r) {
            return root->data + nodeSum(root->left, l, r) + nodeSum(root->right, l, r);
        }
        if (root->data < l) {
            return nodeSum(root->right, l, r);
        }
        
        return nodeSum(root->left, l, r);
    }
};
