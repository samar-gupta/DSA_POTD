//Company Tags     : AMAZON
//Leetcode Link    : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
//Approach - (Converting tree to graph)    //as Binary Tree is a directed graph so can't access parent from child
//T.C : O(n) - visiting all nodes
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
