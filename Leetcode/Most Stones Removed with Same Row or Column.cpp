//Company Tags  : Google
//Leetcode Link : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

//Approach-1 : (Using DFS)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int n ;
    void dfs(vector<vector<int>>& stones, int index, vector<bool>& visited) {
        visited[index] = true;
        
        for(int i = 0; i<n; i++) {
            if(!visited[i] &&
               ((stones[i][0] == stones[index][0]) || (stones[i][1] == stones[index][1]))) {
                dfs(stones, i, visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        vector<bool> visited(n, false);
        
        int count = 0;
        for(int i = 0; i<n; i++) {
            if(visited[i])
                continue;
            dfs(stones, i, visited);
            count++;
        }
        
        return n - count;
    }
};



//Approach-2 : (Using DSU)
//T.C : O(n^2 * α(n))
//S.C : O(n)
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int n;
    
    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]);
        
        return parent[i];
    }
    
    void Union(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        
        if(root_i != root_j) {
            if(rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else  if(rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else {
                parent[root_j] = root_i;
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        parent.resize(n);
        rank.resize(n);
        
        for(int i = 0; i<n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    Union(i, j);
            }
        }
        
        int groups = 0;
        for(int i = 0; i<n; i++) {
            if(parent[i] == i) groups++;
        }
        
        return n-groups;
    }
};
