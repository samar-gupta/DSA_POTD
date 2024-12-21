//Leetcode Link : https://leetcode.com/problems/maximum-number-of-k-divisible-components/

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
