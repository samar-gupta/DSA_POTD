//Leetcode Link : https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level

//Approach - Simple BFS with hidden problem (minimum swaps to sort unique values)
//T.C : O(n + level * wlogw), level = total levels, w = number of nodes in a level
//S.C : O(n)
class Solution {
public:
    int countMinSwapsToSort(vector<int>& vec) {
        int swaps = 0;
        vector<int> sortedVec(begin(vec), end(vec));
        
        sort(begin(sortedVec), end(sortedVec));

        unordered_map<int, int> mp; //nums[i] -> i
        for(int i = 0; i < vec.size(); i++) {
            mp[vec[i]] = i;
        }

        for(int i = 0; i < vec.size(); i++) {
            if(vec[i] == sortedVec[i])
                continue; //no swap required
            
            int currIdx = mp[sortedVec[i]];
            mp[vec[i]] = currIdx;
            mp[vec[currIdx]] = i;
            swap(vec[currIdx], vec[i]);
            swaps++;
        }

        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);

        int result = 0;

        while(!que.empty()) {
            int n = que.size(); //total nodes in current level
            vector<int> vec;

            while(n--) {
                TreeNode* temp = que.front();
                que.pop();
                vec.push_back(temp->val);

                if(temp->left) {
                    que.push(temp->left);
                }

                if(temp->right) {
                    que.push(temp->right);
                }
            }

            result += countMinSwapsToSort(vec);
        }

        return result;
    }
};
