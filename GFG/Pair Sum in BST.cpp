//Approach-1 : (Using vector & Two-pointer)
class Solution {
  public:
    void inorder(Node* root, vector<int> &v){
      if(root==NULL){
          return;
      }
      inorder(root->left,v);
      v.push_back(root->data);
      inorder(root->right,v);
    }
  
    int isPairSum(vector<int>& A,int X) {
        int i = 0;
        int N=A.size();
        int j = N - 1;
 
        while (i < j) {
            if (A[i] + A[j] == X)
                return 1;
 
            else if (A[i] + A[j] < X)
                i++;
 
            else
                j--;
        }
        return 0;
    }
   
    bool findTarget(Node *root, int target) {
        // your code here.
        vector<int>v;
        inorder(root, v);
        return isPairSum(v,target);
    }
};


//Approach-2 : (Using unordered_set)
class Solution {
  public:
    unordered_set<int>s;
    
    bool findTarget(Node *root, int target) {
        // your code here.
        if(!root) {
            return 0;
        }
   
        if(s.count(target-root->data)) {
            return 1;
        }
        else {
            s.insert(root->data);
        }
        
        return findTarget(root->left,target) || findTarget(root->right,target);
    }
};


//Approach-3 : (Recursive)
//T.C : nlogn  (logn is the height of binary tree for searching target node in tree)
//S.C : O(height of binary tree) (Recursion space stack)
class Solution {
  public:
    bool solve(Node* root, Node* curr, int target) {
        if (curr == nullptr) {
            return false;
        }
        if (findNode(root, target - curr->data, curr)) {
            return true;
        }
        return solve(root, curr->left, target) || solve(root, curr->right, target);
    }
    
    bool findNode(Node* root, int target, Node* curr) {
        if (root == nullptr) {
            return false;
        }
        if (root->data == target && root != curr) {
            return true;
        }
        if (root->data > target) {
            return findNode(root->left, target, curr);
        }
        return findNode(root->right, target, curr);
    }
    
    bool findTarget(Node *root, int target) {
        // your code here.
        if (root == nullptr) {
            return false;
        }
        return solve(root, root, target);
    }
};
