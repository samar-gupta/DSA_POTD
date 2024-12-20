//Leetcode Link : https://leetcode.com/problems/reverse-odd-levels-of-binary-tree

//Approach-1 - Simple BFS
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> que;

        que.push(root);
        int level = 0;

        while(!que.empty()) {
            int n = que.size();

            vector<TreeNode*> levelNodes;
            while(n--) {
                TreeNode* temp = que.front();
                que.pop();
                levelNodes.push_back(temp);

                if(temp->left) {
                    que.push(temp->left);
                }
                if(temp->right) {
                    que.push(temp->right);
                }
            }
            if(level%2 == 1) {
                int l = 0, r = levelNodes.size()-1;
                while(l < r) {
                    int tempVal = levelNodes[l]->val;
                    levelNodes[l]->val = levelNodes[r]->val;
                    levelNodes[r]->val = tempVal;
                    l++;
                    r--;
                }
            }
            level++;
        }

        return root;
    }
};


//Approach-2 - Tricky DFS (explained the trick on how to write such DFS)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    void solve(TreeNode* l, TreeNode* r, int level) {
        if(l == NULL || r == NULL) { //Not leaf
            return;
        }

        if(level%2 == 1) {
            int temp = l->val;
            l->val = r->val;
            r->val = temp;
        }

        solve(l->left, r->right, level+1);
        solve(l->right, r->left, level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root->left, root->right, 1); //root at 0 and left and right child at level = 1
        return root;
    }
};
