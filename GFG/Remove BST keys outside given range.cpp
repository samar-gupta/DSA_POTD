//Approach-1 : 
class Solution {
  public:
    Node* removekeys(Node* root, int l, int r) {
        // code here
        if(root == NULL) return NULL;
        
        if(root->data < l)                               //if root->data not valid <l or >r, then go for greater or lesser
            return removekeys(root->right, l, r);
        if(root->data > r) 
            return removekeys(root->left, l, r);
        
        root->left = removekeys(root->left, l, r);        //if root->data is valid, assign left and right part to the root/node through the function which will surely get the right answer from that part 
        root->right = removekeys(root->right, l, r);
        
        return root;
    }
};
