//updated
//Approach : 
class Solution {
  public:
    Node* key = nullptr;    //target node
    void inorder(Node* root, int& target, unordered_map<Node*, Node*>& mp) {
        if (!root) return;
        if (root->left) {
            mp[root->left] = root;
            inorder(root->left, target, mp);
        }
        if (root->data == target) key = root;
        if (root->right) {
            mp[root->right] = root;
            inorder(root->right, target, mp);
        }
    }
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*, Node*> mp;    //parent
        unordered_map<Node*, bool> vis;
        inorder(root, target, mp);       //inorder to store parent
        int t = -1;         //time counter
        queue<Node*> q;
        q.push(key);
        vis[key] = true;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                Node* node = q.front();
                q.pop();
                if (node->left && !vis[node->left]) {
                    vis[node->left] = true;
                    q.push(node->left);
                }
                if (node->right && !vis[node->right]) {
                    vis[node->right] = true;
                    q.push(node->right);
                }
                if (mp[node] && !vis[mp[node]]) {       //root node doesn't have parent and will give segmentation error if we don't write mp[node] along with !visited[mp[node]]
                    vis[mp[node]] = true;
                    q.push(mp[node]);
                }
            } t++;
        } return t;
    }
};



//old
//Approach-1 : (Convert tree to graph)
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
