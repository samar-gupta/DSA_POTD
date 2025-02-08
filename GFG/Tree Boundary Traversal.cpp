class Solution {
  public:
    
    void traverseLeft(Node* root,vector<int>& ans){
        
        // Base Case
        if((root==NULL) || (root->left == NULL && root->right == NULL)) return;
        ans.push_back(root->data);
        
        if(root->left) traverseLeft(root->left,ans);
        else traverseLeft(root->right,ans);
        
    }
    
    void traverseLeaf(Node* root,vector<int>& ans){
        
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
        
    }

    void traverseRight(Node* root,vector<int>& ans){
        
        if((root==NULL) || (root->left == NULL && root->right == NULL)) return;
        if(root->right) traverseRight(root->right,ans);
        else traverseRight(root->left,ans);
        
        // Reverse order mai store karlo
        ans.push_back(root->data);
        
    }

    vector <int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(root == NULL) return ans;
        ans.push_back(root->data);
        
        // Step1 : Traverse Left Part
        traverseLeft(root->left,ans);
        
        // Step2: Traverse Leaf Nodes
        traverseLeaf(root->left,ans); // Left Subtree
        traverseLeaf(root->right,ans); // Right Subtree
        
        // Step3: Traverse Right Part
        traverseRight(root->right,ans);
       
       return ans;
    }
};
