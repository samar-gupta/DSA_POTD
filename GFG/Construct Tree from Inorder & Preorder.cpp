class Solution {
  public:
  
    int pos;
    
    Node* solve(vector<int> &inorder, vector<int> &preorder, int str, int end){
        if(str>inorder.size() || str>end){
            return NULL;
        }
        Node* root = new Node(preorder[pos]);
        int div = 0;
        for(int i=str;i<=end;i++){
            if(preorder[pos] == inorder[i]){
                div = i;
                break;
            }
        }
        pos++;
        root->left = solve(inorder, preorder, str, div-1);
        root->right = solve(inorder, preorder, div+1, end);
        return root;
    }
    
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        pos = 0;
        return solve(inorder, preorder, 0, inorder.size()-1);
    }
};
