//Company Tags   : Microsoft
//Leetcode Link  : https://leetcode.com/problems/find-bottom-left-tree-value/

//Approach-1 (Using DFS)
//T.C : O(n)
//S.C : O(max depth of tree)
class Solution {
public:
    int maxDepth;
    int bottomLeft;
    
    void solve(TreeNode* root, int currDepth) {
        if(!root) {
            return;
        }
        
        if(currDepth > maxDepth) {
            maxDepth   = currDepth;
            bottomLeft = root->val;
        }
        
        solve(root->left, currDepth+1);
        solve(root->right, currDepth+1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        maxDepth = -1;
        
        solve(root, 0);
        return bottomLeft;
        
    }
};


//Approach-2 (Using BFS)
//T.C : O(n)
//S.C : O(n) for queue
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        
        int bottomLeft;
        que.push(root);
        
        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            
            bottomLeft = node->val;
            
            if(node->right) {
                que.push(node->right);
            }
            if(node->left) {
                que.push(node->left);
            }
        }
        
        return bottomLeft;
    }
};


//Approach-3 (Using BFS with inner while loop)  (Level Wise)
//T.C : O(n)
//S.C : O(n) for queue
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        
        int bottomLeft;
        que.push(root);
        
        while(!que.empty()) {
            int n = que.size();

            while(n--) {
                TreeNode* node = que.front();
                que.pop();
                
                
                bottomLeft = node->val;
                
                if(node->right) {
                    que.push(node->right);
                }
                if(node->left) {
                    que.push(node->left);
                }
            }
            
        }
        
        return bottomLeft;
    }
};
