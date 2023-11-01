/*
    Company Tag                 : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/find-mode-in-binary-search-tree/
*/

/********************************************* C++ ************************************************************/
//Approach-1 (Using O(n) space)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    unordered_map<int, int> mp;
    
    void dfs(TreeNode* root) {
        if(!root)                 //root == NULL
            return;
        
        dfs(root->left);
        mp[root->val]++;
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        
        vector<int> result;
        int maxFreq = 0;
        
        for(auto &it : mp) {
            if(it.second > maxFreq) {
                maxFreq = it.second;
                result = {};
                result.push_back(it.first);
            } else if (it.second == maxFreq) {
                result.push_back(it.first);
            }
        }
        
        return result;
    }
};




//Approach-2 (without Using extra space)
//T.C : O(n)
//S.C : O(1) (stack space is not considered)
class Solution {
public:
    int currNum = 0;
    int currFreq = 0;
    int maxFreq = 0;
    vector<int> result;

    void dfs(TreeNode* root) {
        if(!root)
            return;

        dfs(root->left);

        if(root->val == currNum) {
            currFreq++;
        } else {
            currNum = root->val;
            currFreq = 1;
        }

        if(currFreq > maxFreq) {
            result = {};
            maxFreq = currFreq;
        }

        if(currFreq == maxFreq) {
            result.push_back(root->val);
        }

        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);

        return result;
    }
};
