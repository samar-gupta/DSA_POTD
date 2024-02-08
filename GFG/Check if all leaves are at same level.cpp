class Solution{
  public:
    
    bool check(Node *root)
    {
        if(!root) return true;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        int same = -1;
        
        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                Node* node = q.front().first;
                int level = q.front().second;
                q.pop();
                
                if(!node->left && !node->right) {
                    if(same == -1) same = level;
                    else if(same != level) return false;
                }
                
                if(node->left) q.push({node->left, level+1});
                if(node->right) q.push({node->right, level+1});
            }
        }
        
        return true;
    }
};
