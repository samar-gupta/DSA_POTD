//Leetcode Link    : https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

//Approach-1 (Simple and straight forward)
//T.C : O(n)
//S.C : O(1) (I am ignoring stack recursive space, else S.C  will be O(height of tree))
class Solution {
public:
    int result = 0;
    
    void solve(TreeNode* root, vector<int>& temp) {
        if(root != NULL) {
            temp[root->val]++;
            
            if(root->left == NULL && root->right == NULL) {
                int oddFreq = 0;
                for(int i = 1; i <= 9; i++) {
                    if(temp[i]%2 != 0) {
                        oddFreq++;
                    }
                }

                result += oddFreq <= 1;
            }
            
            
            solve(root->left, temp);
            solve(root->right, temp);
            
            temp[root->val]--;

        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> temp(10, 0);
        
        solve(root, temp);
        return result;
    }
};





//Approach-2 (Using bit magic)
//T.C : O(n)
//S.C : O(1) (I am ignoring stack recursive space, else S.C  will be O(height of tree))
class Solution {
public:
    int result = 0;
    
    void solve(TreeNode* root, int temp) {
        if(root != NULL) {
            
            temp = temp ^ (1 << root->val);
            
            if(root->left == NULL && root->right == NULL) {
                if((temp & (temp - 1)) == 0) {       //Make sure to put (temp & (temp - 1)) entirely in bracket because precedence of == is high
                    result++;
                }
            }
                  
            solve(root->left, temp);
            solve(root->right, temp);
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {

        solve(root, 0);
        return result;
    }
};
