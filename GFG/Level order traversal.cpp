//Approach : Using Queue (updated)
class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        vector<vector<int>> ans;
        if (!root) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            
            while (size-- > 0) {
                Node* tmp = q.front();
                q.pop();
                level.push_back(tmp->data);
                
                if (tmp->left) {
                    q.push(tmp->left);
                }
                if (tmp->right) {
                    q.push(tmp->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};


//Approach(old version)
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      //Your code here
      queue<Node*>q;
      q.push(root);
      
      vector<int>ans;
      while(!q.empty()){
          Node* node=q.front();
          q.pop();
          
          ans.push_back(node->data);
          if(node->left){
              q.push(node->left);
          }
          
          if(node->right){
              q.push(node->right);
          }
          
      }
      return ans;
    }
};
