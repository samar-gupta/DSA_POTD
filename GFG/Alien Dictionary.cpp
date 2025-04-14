class Solution {
public:
    bool dfs(int u, vector<vector<int>>& graph, vector<int>& vis,
             vector<int>& rec, string& ans) {
        vis[u] = rec[u] = 1;

        for (int v = 0; v < 26; v++) {
            if (graph[u][v]) {
                if (!vis[v]) {
                    if (!dfs(v, graph, vis, rec, ans))
                        return false;
                } else if (rec[v]) {
                    return false;
                }
            }
        }
        ans.push_back(char('a' + u));
        rec[u] = 0;
        return true;
    }
    string findOrder(vector<string>& words) {
        vector<vector<int>> graph(26, vector<int>(26, 0));
        vector<int> exist(26, 0);
        vector<int> vis(26, 0);
        vector<int> rec(26, 0);
        string ans = "";

        for (string word : words) {
            for (char ch : word) {
                exist[ch - 'a'] = 1;
            }
        }

        for (int i = 0; i + 1 < words.size(); i++) {
            const string &a = words[i], &b = words[i + 1];
            int n = a.size(), m = b.size(), ind = 0;

            while (ind < n && ind < m && a[ind] == b[ind])
                ind++;

            if (ind != n && ind == m)
                return "";

            if (ind < n && ind < m)
                graph[a[ind] - 'a'][b[ind] - 'a'] = 1;
        }

        for (int i = 0; i < 26; i++) {
            if (exist[i] && !vis[i]) {
                if (!dfs(i, graph, vis, rec, ans)) {
                    return "";
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//old
class Solution{
    public:
    string findOrder(string dict[], int n, int K) {
        // topo sort bfs
        vector<int> adj[K], indeg(K);
        for(int i=0;i<n-1;i++) {
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.length(),s2.length());
            for(int j=0;j<len; j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    indeg[s2[j] - 'a']++;
                    break;
                }
            }
        }
        queue<int> q;
        for(int i=0;i<K;i++) {
            if(indeg[i] == 0) q.push(i);
        }
        string ans;
        while(q.size()) {
            int node = q.front();
            q.pop();
            ans.push_back(char(node + 'a'));
            for(int i : adj[node]) {
                indeg[i]--;
                if(indeg[i] == 0) q.push(i);
            }
        }
        return ans;
    }
};
