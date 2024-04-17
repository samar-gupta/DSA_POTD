//Leetcode Link  : https://leetcode.com/problems/smallest-string-starting-from-leaf/

//Approach-1 (Using DFS)
//T.C : O(n)
//S.C : O(n) space taken for resurion system stack
class Solution {
public:
    string result = "";
    
    
    void solve(TreeNode* root, string curr) {
        if(root == NULL) {
            return;
        }
        
        curr = char(root->val + 'a') + curr; //This will take O(length of curr) but I have ignored this. You can condiser this as well in calculating T.C
        
        if(root->left == NULL && root->right == NULL) {
            if(result == "" || result > curr) {
                result = curr;
            }
            return;
        }
        
        solve(root->left, curr);
        solve(root->right, curr);
        
        
    }
    
    string smallestFromLeaf(TreeNode* root) {
        solve(root, "");
        
        return result;
    }
};



//Approach-2 (Using BFS)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        queue<pair<TreeNode*, string>> que;
        
        string result = "";
        que.push({root, string(1, root->val + 'a')});
        
        while(!que.empty()) {
            
            auto[node, curr] = que.front();
            que.pop();
            
            if(node->left == NULL && node->right == NULL) {
                if(result == "" || result > curr) {
                    result = curr;
                }
            }
            
            if(node->left) {
                que.push({node->left, char(node->left->val + 'a') + curr});
            }
            
            if(node->right) {
                que.push({node->right, char(node->right->val + 'a') + curr});
            }
            
        }
        
        return result;
    }
};
