// Approach-1 :
// T.C : O(n^2)
class Solution {
  public:
    bool isValidBST(Node *root, int minVal, int maxVal) {
        if (root == NULL) return true;
        
        if (root->data >= maxVal || root->data <= minVal) return false;
        
        return isValidBST(root->left, minVal, root->data) &&
               isValidBST(root->right, root->data, maxVal);
    }
    
    int size(Node* root){
        if (root == NULL) return 0;
        return size(root->left) + size(root->right) + 1;
    }
    
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        // Your code here
        if (root == NULL) return 0;
        
        if (isValidBST(root, INT_MIN, INT_MAX)) {
            return size(root);
        }
        
        return max(largestBst(root->left), largestBst(root->right));
    }
};



// Approach-2 :
// T.C : O(n)
/*
   It was checking BST validity repeatedly for each subtree,
   leading to O(n²). I optimized it using a bottom-up approach 
   where each node returns BST info, reducing it to O(n).
*/
class Solution {
  public:
    
    struct Info {
        int size;      // size of subtree
        int min;       // min value in subtree
        int max;       // max value in subtree
        int ans;       // size of largest BST
        bool isBST;    // is subtree BST
    };
    
    Info solve(Node* root) {
        if (root == NULL) {
            return {0, INT_MAX, INT_MIN, 0, true};
        }
        
        if (root->left == NULL && root->right == NULL) {
            return {1, root->data, root->data, 1, true};
        }
        
        Info left = solve(root->left);
        Info right = solve(root->right);
        
        Info curr;
        curr.size = 1 + left.size + right.size;
        
        // Check BST condition
        if (left.isBST && right.isBST &&
            left.max < root->data && root->data < right.min) {
            
            curr.min = min(left.min, root->data);
            curr.max = max(right.max, root->data);
            curr.ans = curr.size;
            curr.isBST = true;
            
            return curr;
        }
        
        // Not BST
        curr.ans = max(left.ans, right.ans);
        curr.isBST = false;
        return curr;
    }
    
    int largestBst(Node *root) {
        return solve(root).ans;
    }
};



// old - 1
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    bool isBST(Node* root,int mn, int mx){
        if(!root) return true;
        if(root->data < mn || root->data > mx ) return false;
        return isBST(root->left, mn, root->data-1) && isBST(root->right,root->data+1,mx);
    }
    
    int sizeOfBst(Node* root){
        if(root==NULL) return 0;
        queue<Node *> q;
        q.push(root);
        int count=1;
        while(!q.empty()){
            Node * node=q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                count++;
            }
            if(node->right){
                q.push(node->right);
                count++;
            }
        }
        return count;
    }
    
    int largestBst(Node *root)
    {
    	queue<Node*> q;
    	int ans=0;
    	q.push(root);
    	while(!q.empty()){
    	    Node* node=q.front();
    	    q.pop();
    	    if(isBST(node, INT_MIN, INT_MAX)){
    	        int size=sizeOfBst(node);
    	        ans=max(ans,size);
    	    }
    	    if(node->left) q.push(node->left);
    	    if(node->right) q.push(node->right);
    	}
    	return ans;
    }
};
