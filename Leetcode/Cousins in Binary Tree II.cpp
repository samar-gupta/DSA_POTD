//Leetcode Link : https://leetcode.com/problems/cousins-in-binary-tree-ii

//Approach-1 (2 Pass)
//T.C : O(2*n)
//S.C : O(n)
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL)
            return root;

        queue<TreeNode*> que;
        que.push(root);
        vector<int> levelSum;

        //Step-1 (find sum of each level and store in levelSum array)
        while(!que.empty()) {
            int currLevelSum = 0;
            int n = que.size();
            while(n--) {
                TreeNode* curr = que.front();
                que.pop();
                currLevelSum += curr->val;
                if(curr->left) {
                    que.push(curr->left);
                }
                if(curr->right) {
                    que.push(curr->right);
                }
            }

            levelSum.push_back(currLevelSum);
        }
        cout << levelSum.size() << endl;

        //Step-2 (update each node value with cousin sum)
        que.push(root);
        root->val = 0; //root has not cousins
        int i = 1;
        while(!que.empty()) {
            int n = que.size(); //current level me kitne nodes hain

            while(n--) {
                TreeNode* curr = que.front();
                que.pop();

                //levelSum of currentLevel - sibilnigSum
                int siblingSum = curr->left != NULL ? curr->left->val : 0;
                siblingSum += curr->right != NULL ? curr->right->val : 0;

                if(curr->left) {
                    curr->left->val = levelSum[i] - siblingSum;
                    que.push(curr->left);
                }
                if(curr->right) {
                    curr->right->val = levelSum[i] - siblingSum;
                    que.push(curr->right);
                }
            }
            i++;
        }

        return root;

    }
};


//Approach-2 (1 Pass)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL) {
            return root;
        }        

        queue<TreeNode*> que;
        que.push(root);
        int levelSum = root->val;

        while(!que.empty()) {
            int n = que.size();
            int nextLevelSum = 0;

            while(n--) {
                TreeNode* curr = que.front();
                que.pop();

                curr->val = levelSum - curr->val;

                int siblingSum = (curr->left != NULL ? curr->left->val : 0);
                siblingSum += (curr->right != NULL ? curr->right->val : 0);

                if(curr->left) {
                    nextLevelSum += curr->left->val;
                    curr->left->val = siblingSum;
                    que.push(curr->left);
                }


                if(curr->right) {
                    nextLevelSum += curr->right->val;
                    curr->right->val = siblingSum;
                    que.push(curr->right);
                }
            }

            levelSum = nextLevelSum;
        }

        return root;
    }
};
