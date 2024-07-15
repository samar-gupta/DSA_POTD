//Company Tags  : Uber
//Leetcode Link : https://leetcode.com/problems/create-binary-tree-from-descriptions/description

//Simple Approach using map and set
//T.C : O(n), where n is the size of descriptions
//S.C : O(n), size of map and set
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childSet; //they can never be root of the tree


        for(vector<int>& vec : descriptions) { //O(n)
            int parent = vec[0];
            int child  = vec[1];
            int isLeft = vec[2];

            if(mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }

            if(mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }

            if(isLeft == 1) { //left child  
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }

            childSet.insert(child);
        }


        //Find the root
        for(vector<int>& vec : descriptions) { //O(n)
            int parent = vec[0];
            if(childSet.find(parent) == childSet.end()) { //if(!mp.count(parent))
                return mp[parent];
            }
        }

        return NULL; //we will never reach here
    }
};
