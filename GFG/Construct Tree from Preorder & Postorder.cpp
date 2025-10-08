//Approach-1 : 
/*
Intuition : 
   1. Preorder: Root → Left → Right
      The first element in pre[] is always the root of the current subtree.

   2. Postorder: Left → Right → Root
      The last element in post[] is the root of the current subtree.

   3. Using both arrays together, we can recursively build the tree:
      Take the next element from pre[] as root.
          • If root’s value is not equal to current post[] element, it means the left child exists → recursively build left.
          • If root’s value is still not equal to post[] element, it means the right child exists → recursively build right.
          • After building children, move postIndex forward because this root is now fully processed.
*/
//TC : O(n) → each node is visited once.
//SC : O(n) → recursion stack in worst case (skewed tree).
class Solution {
  public:
    int preIndex = 0, posIndex = 0;
    
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        // code here
        Node* root = new Node(pre[preIndex++]);
        
        if(root->data != post[posIndex]){
            root->left = constructTree(pre, post);
        }
            
        if(root->data != post[posIndex]){
            root->right = constructTree(pre, post);
        }
            
        posIndex++;
        
        return root; 
    }
};
