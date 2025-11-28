//Leetcode Link : https://leetcode.com/problems/maximum-number-of-k-divisible-components/

//Approach (Using DFS) - You can easily replace DFS with BFS as well
//T.C : O(n) - We visit all nodes once
//S.C : O(n-1) ~ O(n) - We store edges in the adjacency list
class Solution {
public:
    int count = 0;
    int dfs(int curr, int parent,
            unordered_map<int, vector<int>> &adj,
            vector<int> &values, int k) {
        

        int sum = 0;

        for (int &ngbr : adj[curr]) {
            if (ngbr != parent) {
                sum += dfs(ngbr, curr, adj, values, k);
                sum %= k;
            }
        }

        sum += values[curr];
        sum %= k;

        if (sum == 0) 
            count++;

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                                vector<int> &values, int k) {

        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        count = 0;

        dfs(0, -1, adj, values, k);

        return count;
    }
};


//Approach-1 :
class Solution {
public:
    int ans=0;
    long long helper(vector<int> adj[],int node,int k,vector<int>& values,vector<int> &vis){
        vis[node]=1;
        long long sum=0;
        for(auto a:adj[node]){
            if(vis[a]) continue;
            sum+=helper(adj,a,k,values,vis);
        };
        sum+=values[node];
        if(sum%k==0){
            ans++;
            return 0;
        }
        return sum;

    }
    
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> vis(n,0);
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        helper(adj,0,k,values,vis);
        return ans;
    }
};
