//Approach-1 : (BFS)
class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
       while(!q.empty()){
           int size=q.size();
           ans.push_back(q.front()->data);
           while(size--){
               Node* t=q.front();
               q.pop();
               if(t->left) q.push(t->left);
               if(t->right) q.push(t->right);
            }
        }
        return ans;
    }
};


//Approach-2 : (DFS)
class Solution {
  public:
    void solve(Node* root, vector<int> &ans, int level) {
        // base case
       if(root == NULL)
           return ;
   
       // we entered in new level if below condition is true
       if(level == ans.size())
           ans.push_back(root -> data);
   
        solve(root -> left, ans, level + 1);
        solve(root -> right, ans, level + 1);
    }

    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};
