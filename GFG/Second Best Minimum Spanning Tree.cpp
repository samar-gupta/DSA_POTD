//Approach-1 :
/*
See the Question asks a simple thing to find second possible mst. 
Now we know how to find a mst --> either thorugh prims algo or through kruskals algo.
we {cannot} use prims algo because it works on priority_queue and finding different msts would be quite confusing , so better is that we use kruskals algo.
Kruskal's algo uses DSU concept .
Logic of how to solve this problem.
first Find the primary mst -->the main minimum spanning tree and keep a track of all the vertices which u have used in making the spanning tree. 
In my solution I am keeping a used array to keep a track of the vertices which I have used.
See one example : is that if suppose you have 5 vertices and 10 edges , 
now best 4 edges will be used to make the best spanning tree out of 10 , the remaning 6 edges are of no use . 
we can store the answer of this best mst as primary mst , now we will try to generate all other msts by removing one of the 4 edges which we have used earlier , 
suppose I remove 1st used edge , then I have other 9 choices to make mst , if mst is possible from these 9 choices I will make it and check the answer of the new_mst , 
surely its weight will be greater than the best primary_mst , now do this for 2nd , 3rd , 4th vertices individually , do not use those vertices and try making msts from other 9 choices , from all of the other edge weigths ,
I have to take the minimum edge weight out there possible . and in this way I will be able to generate the second possible mst.
since no of vertices are of order 1e2 and max edges can be of order 1e4 , the worst case time complexity can go upto 1e2*1e4==1e6 , for every vertice I am trying out all the other edges , t
his will surely pass the time constraints.
the question would have been difficult if constraints would be high , then binary lifting concept had to be used but here it will work fine.
*/
class Solution {
  public:
    class DSU{
     public:
     int n;
     vector<int>parent;
     vector<int>sz;
     
     DSU(int v){
         n=v;
         parent.resize(n,1);
         sz.resize(n,1);
         for(int i=0;i<n;i++){
             parent[i]=i;
         }
     }
     
     int Find(int u){
         if(parent[u]==u) return u;
         return parent[u]=Find(parent[u]);
     }
     
     void Union(int u , int v){
         int pu = Find(u);
         int pv = Find(v);
         if(pu==pv){
             return;
         }
         
         if(sz[pv]>sz[pu]){
             parent[pu]=pv;
             sz[pv]+=sz[pu];
         }
         else{
             parent[pv]=pu;
             sz[pu]+=sz[pv];
         }
     }
        
    };
    
    int mst_weight(int vertices , int to_not_use , vector<vector<int>> &edges , vector<int>&used){
        int n = edges.size();
        int mst_wt=0;
        int count_edges=0;
        
        DSU dsu(vertices);
        
        for(int i=0;i<n;i++){
            if(i==to_not_use) continue;
            int u = edges[i][0];
            int v = edges[i][1];
            int wt=edges[i][2];
            
            if(dsu.Find(u) != dsu.Find(v)){
                dsu.Union(u,v);
                mst_wt+=wt;
                count_edges++;
                used[i]=1;
            }
        }
        
        if(count_edges != vertices-1) return -1;
        return mst_wt;
    }
    int secondMST(int n, vector<vector<int>> &edges) {
        // code here
        
        int m = edges.size();
        
        if(m<=n-1) return -1;
        
        auto mysort = [&](const auto&a , const auto&b){
            return a[2]<b[2];
        };
        
        sort(edges.begin(),edges.end(),mysort);
        
        vector<int>used(m,0);
        
        int primary_mst_wt = mst_weight(n,-1,edges,used);
        
        if(primary_mst_wt == -1) return -1;
        
        vector<int>copy_used = used;
        
        int ans=INT_MAX;
        
        for(int i=0;i<m;i++){
            if(copy_used[i]==1){
                int secondary_mst_wt = mst_weight(n,i,edges,used);
                if(secondary_mst_wt != -1 && secondary_mst_wt > primary_mst_wt){
                    ans=min(ans,secondary_mst_wt);
                }
            }
        }
        
        if(ans==INT_MAX) return -1;
        return ans;
        
    }
};
