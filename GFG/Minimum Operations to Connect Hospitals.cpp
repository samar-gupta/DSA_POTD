//Approach-1 : (Question Similar to Connecting the Graph)
class disjointSet{
    public:
    vector<int> parent,rank,size;
    
    disjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        size.resize(n+1);
        
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
            rank[i]=0;
        }
    }
    
    int findUPar(int node){
        if(parent[node]==node){
            return node;
        }
        
        return parent[node]=findUPar(parent[node]);
    }
    
    void unionByRank(int u,int v){
        int ultP_u=findUPar(u);
        int ultP_v=findUPar(v);
        
        if(ultP_u==ultP_v){
            return;
        }
        
        if(rank[ultP_u]<rank[ultP_v]){
            parent[ultP_u]=ultP_v;
        }
        else if(rank[ultP_v]<rank[ultP_u]){
            parent[ultP_v]=ultP_u;
        }
        else{
            parent[ultP_v]=ultP_u;
            rank[ultP_u]++;
        }
    }
    
    void unionBySize(int u,int v){
        int ultP_u=findUPar(u);
        int ultP_v=findUPar(v);
        
        if(ultP_u==ultP_v){
            return;
        }
        
        if(size[ultP_u]<size[ultP_v]){
            parent[ultP_u]=ultP_v;
            size[ultP_v]+=size[ultP_u];
        }
        else{
            parent[ultP_v]=ultP_u;
            size[ultP_u]+=size[ultP_v];
        }
    }
};


class Solution {
  public:
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here
        disjointSet ds(V);
        int extraEdges=0;
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            
            if(ds.findUPar(u)==ds.findUPar(v)){
                extraEdges++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        
        int numComponents=0;
        
        for(int i=0;i<V;i++){
            if(ds.parent[i]==i){
                numComponents++;
            }
        }
       
// numComponents-1 means no. of edges require to connect n connected component 
        if(extraEdges>=numComponents-1){
            return (numComponents-1);
        }
        
        return -1;
        
    }
};
