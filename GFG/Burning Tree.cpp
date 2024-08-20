//Approach-1 (Convert tree to graph)
//T.C : O(n) - visiting all nodes
//S.C : O(n) - storing all nodes in graph
class Solution {
public:
    void convert(Node* current, int parent, unordered_map<int, vector<int>>& adj) {
        if (current == nullptr) {
            return;
        }

        if (parent != -1) {
            adj[current->data].push_back(parent);
        }

        if (current->left != nullptr) {
            adj[current->data].push_back(current->left->data);
        } 
        if (current->right != nullptr) {
            adj[current->data].push_back(current->right->data);
        }
        convert(current->left, current->data, adj);
        convert(current->right, current->data, adj);
    }

    int minTime(Node* root, int start) {
        unordered_map<int, vector<int>> adj;
        convert(root, -1, adj);

        queue<int> que;
        que.push(start);
        unordered_set<int> visited;
        visited.insert(start);
        int minutes = 0;

        while (!que.empty()) {
            int n = que.size();

            while (n--) {
                int curr = que.front();
                que.pop();

                for (int &ngbr : adj[curr]) {
                    if (visited.find(ngbr) == visited.end()) {
                        que.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
            }
            minutes++;
        }

        return minutes - 1;
    }
};



//Approach-2 (Using DFS - one pass solution)
//T.C : O(n)
//S.C : O(n) - Max depth of recursion call stack
class Solution {
public:
    int result = INT_MIN;

    int solve(Node* root, int start) {
        if(root == NULL) {
            return 0;
        }

        int LH = solve(root->left, start);
        int RH = solve(root->right, start);

        if(root->data == start) {
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

    int minTime(Node* root, int start) {
        solve(root, start);

        return result;
    }
};
