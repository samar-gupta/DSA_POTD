//Company Tags     : AMAZON
//Leetcode Link    : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
//Approach - (Converting tree to graph)    //as Binary Tree is a directed graph so can't access parent from child
//T.C : O(n) - visiting all nodes         //O(2n)
//S.C : O(n) - storing all nodes in graph

class Solution {
public:
    void makeGraph(unordered_map<int, vector<int>> &adj, int parent, TreeNode* curr) {
        if(curr == NULL)
            return;

        if(parent != -1) {
            adj[curr->val].push_back(parent);
        }

        if(curr->left) {
            adj[curr->val].push_back(curr->left->val);
        }

        if(curr->right) {
            adj[curr->val].push_back(curr->right->val);
        }

        makeGraph(adj, curr->val, curr->left);
        makeGraph(adj, curr->val, curr->right);
    }


    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        makeGraph(adj, -1, root);
        
        queue<int> que;                           //Applying BFS from start
        unordered_set<int> visited;
        que.push(start);
        visited.insert(start);
        
        int minutes = 0;

        while(!que.empty()) {

            int n = que.size();

            while(n--) {
                int curr = que.front();
                que.pop();

                for(int &ngbr : adj[curr]) {

                    if(visited.find(ngbr) == visited.end()) {
                        que.push(ngbr);
                        visited.insert(ngbr);
                    }

                }
            }
            minutes++;
        }

        return minutes-1;
    }

};






//Approach-2 (Using DFS - one pass solution)
//T.C : O(n)
//S.C : O(n) - Max depth of recursion call stack
class Solution {
public:
    int result = INT_MIN;

    int solve(TreeNode* root, int start) {
        if(root == NULL) {
            return 0;
        }

        int LH = solve(root->left, start);
        int RH = solve(root->right, start);

        if(root->val == start) {
            result = max(LH, RH);
            return -1;
        } else if(LH >= 0 && RH >= 0) {
            return max(LH, RH) + 1;
        } else {
            int d = abs(LH) + abs(RH);
            result = max(result, d);

            return min(LH, RH) - 1;
        }

        return 0;
    }

    int amountOfTime(TreeNode* root, int start) {
        solve(root, start);

        return result;
    }
};
