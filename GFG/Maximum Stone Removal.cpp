//Approach-1 : (using Disjoint Set but without using map)
/*
  So we have to find the connected components of stones 
  and then deduct it from the total no of stones 
  but we don't want to count single nodes as a component.
  For this we can use the size array of our Disjoint Set class 
  and use it to find the nodes which are single and skip it while counting components.
*/
class DisjointSet {
public:
vector<int> rank, parent,size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1,0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i]=1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones) {
        // code here
        int n = stones.size();
        int maxRow=0;
        int maxCol=0;
        
        for(auto it:stones){
            maxRow=max(it[0],maxRow);
            maxCol=max(it[1],maxCol);
        }
        DisjointSet ds(maxRow+maxCol+1);
        
        for(auto it:stones){
            int row = it[0];
            int col = it[1] + maxRow + 1;
            
            if(ds.findUPar(row)!=ds.findUPar(col))
                ds.unionBySize(row,col);
        }
        
        int cnt=0;
        for(int i = 0; i < maxRow + maxCol + 1; i++)
            if(ds.parent[i] == i && ds.size[i] > 1)
                cnt++;
            
        return n - cnt;
    }
};
