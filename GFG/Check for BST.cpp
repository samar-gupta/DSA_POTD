//(updated)
class Solution {
  public:
    bool isValidBST(Node *root,int mini,int maxi) {
        if(root==NULL)
            return true;
        if(root->data > maxi || root->data < mini)
            return false;
        return (isValidBST(root->left,mini,root->data) && isValidBST(root->right,root->data,maxi));
    }
    
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // Your code here
        return isValidBST(root,INT_MIN,INT_MAX);
    }
};


//(old version)
class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    void inorder(Node* root,vector<int> &arr){
        if(!root) return;
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
    bool isBST(Node* root) {

        vector<int> arr;
        inorder(root,arr);
        int n=arr.size();
        if(n==1 or n==0) return true;
        for(int i=1;i<n;i++){
            if(arr[i-1]>=arr[i]) return false;
        }
        return true;
    }
};
