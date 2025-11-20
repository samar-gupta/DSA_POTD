//Approach-1 : 
/*
  Key Idea :                          
      We have 26 lowercase letters → treat each as a graph node.
      transform[i][0] → transform[i][1] with weight cost[i].
      We want to make s[i] and t[i] equal by converting both to some intermediate character k (where k ∈ 'a'..'z') with minimum total cost:
        bestCost(s[i],t[i])=min(dist[s[i]][k]+dist[t[i]][k]) , where k∈(0....25)
      If this is impossible → return -1.

  Step-by-step Plan :
      1. Build a 26×26 graph
          • dist[u][v] = minimum cost to convert u → v
          • Initialize:
              dist[i][i] = 0
              For given transforms: dist[x][y] = min(dist[x][y], cost)

      2. Run Floyd–Warshall on 26 nodes
          Even though constraints ask for O(n),
          26 is constant → 26³ = 17,576 operations → constant time → counted as O(1).
          This gives us shortest cost between all pairs of characters.

      3. For each index i
          Find minimal cost to convert both characters to the same final character.
          If no such final character exists (infinite dist) → return -1.

  Why Floyd-Warshall?
      Because transformations can be chained:
      a → b → c → d
      Floyd-Warshall will find these minimum paths.


  Complexity :  
      Time Complexity:
          Floyd-Warshall on 26 letters → O(1) (constant)
          Processing each index of strings → O(n)
          Final TC: O(n)          
      Space Complexity:
          26×26 distance matrix → O(1) (constant)
          Final SC: O(1)
*/
class Solution {
  public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        // code here
        int n=s.size();
        
        // 26x26 distance matrix
        const int INF=1e9;
        vector<vector<int>> dist(26,vector<int>(26,INF));
        
        for(int i=0;i<26;i++){
            dist[i][i]=0;
        }
            
        
        // fill direct transform costs
        for(int i=0;i<transform.size();i++) {
            int u=transform[i][0]-'a';
            int v=transform[i][1]-'a';
            dist[u][v]=min(dist[u][v],cost[i]);
        }
        
        // Floyd–Warshall for 26 letters
        for(int k=0;k<26;k++) {
            for(int i=0;i<26;i++) {
                for(int j=0;j<26;j++) {
                    if(dist[i][k]<INF && dist[k][j]<INF)
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        
        long long ans=0;
        
        // For each position, find the best common char
        for(int i=0;i<n;i++) {
            int u=s[i]-'a';
            int v=t[i]-'a';
            
            int best=INF;
            
            for(int k=0;k<26;k++) {
                if(dist[u][k] < INF && dist[v][k] < INF) {
                    best=min(best,dist[u][k]+dist[v][k]);
                }
            }
            
            if(best==INF){
                return -1;
            }
            
            ans+=best;
        }
        
        return ans;
    }
};
