//Approach-1 : (Using Recursion)
class Solution {
  public:
    
    void solve(Node* root, vector<int>& ans) {
        if (root == nullptr)
            return;
        solve(root->left, ans);
        ans.push_back(root->data);
        solve(root->right, ans);
    }
   
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};


//Approach-2 : (Using Stack)
class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> res;
        stack<Node*> s;
        Node* curr = root;
        while(curr or !s.empty()){
            while(curr){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            res.push_back(curr->data);
            curr = curr->right;
        }
        return res;
    }
};


//Approach-2 ; 
class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
          stack<Node*> st;
          
          while (root != nullptr) {
              st.push(root);
              root = root->left;
          }
          
          while (!st.empty()) {
              Node* tmp = st.top();
              st.pop();
              ans.push_back(tmp->data);
              
              if (tmp->right != nullptr) {
                  tmp = tmp->right;
                  while (tmp != nullptr) {
                      st.push(tmp);
                      tmp = tmp->left;
                  }
              }
          }
          
          return ans;
    }
};
