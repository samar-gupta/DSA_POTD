//Approach :
class Solution {
  public:
    vector<vector<int>>dp;
    int solve(int i,int n,vector<vector<int>>&cost,int mask){
        if(mask==0)return cost[i][0];// cost fromt the last city visited to the 
        // start city i.e city 0
    
        if(dp[i][mask]!=-1)return dp[i][mask];
        int ans=1e9+7;
        for(int j=0;j<n;j++){
            if(mask&(1<<j)){
                ans=min(ans,cost[i][j]+solve(j,n,cost,mask^(1<<j)));
               //marking the jth city visited while going from city i to city j
            }
        }
        return dp[i][mask]=ans;
    }
    
    int tsp(vector<vector<int>>& cost) {
        // code here
        int n=cost.size();
        if(n==1)return 0;
    
        int mask=(1<<n)-1;
        dp=vector<vector<int>>(n+1,vector<int>(mask+1,-1));
        mask^=(1<<0);// marking the city 0 visited by unsetting the 0th bit
        return solve(0,n,cost,mask);
    }
};


//Approach :
/*
(Intuition) :
The Travelling Salesman Problem says:
Start from city 0 → visit all cities exactly once → return to city 0 with minimum cost.

Brute force tries all city permutations → (n−1)! time — impossible for n ≤ 15.

So we use Dynamic Programming + Bitmasking to remember:
Which cities are already visited
Current city

Think of DP state as:
dp[mask][i] → minimum cost to reach city i after visiting cities in set 'mask'.
Where mask is a binary representation of visited cities.

Example mask:
mask = 10101 (in binary) → cities 0, 2, 4 are visited
Transition:
From city i, try to visit next city j that isn’t visited yet and update the new mask.


(Approach) :
Let dp[mask][i] be min cost to reach city i with visited set mask.

Start from city 0, so:

dp[1][0] = 0 // mask 000..001 = only 0th city visited
Iterate all masks and all current cities i.

From city i, attempt to go to any unvisited city j and update:

dp[newMask][j] = min(dp[newMask][j], dp[mask][i] + cost[i][j])
After filling DP, check final masks and add the return cost to city 0.


(Dry Run (Small Example)) :
cost = [[0, 111], [112, 0]] Cities: 0 and 1
DP table initially:

dp[01][0] = 0 // only city 0 visited
Mask = 01, current city = 0
Go to city 1:

newMask = 11 dp[11][1] = dp[01][0] + cost[0][1] = 0 + 111 = 111
Now final mask = 11 (all cities visited)
We try to return back to city 0:

dp[11][1] + cost[1][0] = 111 + 112 = 223
So ans = 223.


(Time and Space Complexity) :
Metric	Complexity
Time	O(n² · 2ⁿ)
Space	O(n · 2ⁿ)
*/
class Solution {
  public:
    int tsp(vector<vector<int>>& cost) {
        // code here
        int n=cost.size();
        int N=1<<n;
        const int INF=1e9;

        vector<vector<int>> dp(N,vector<int>(n,INF));
        
        dp[1][0]=0;

        for(int mask=0;mask<N;mask++){
            
            for(int i=0;i<n;i++){
                
                if(!(mask & (1<<i))){
                    continue;
                } 
                
                if(dp[mask][i]==INF){
                    continue;
                }

                for(int j=0;j<n;j++){
                    
                    if(mask & (1<<j)){
                        continue;
                    } 
                    
                    int newMask=mask | (1<<j);
                    dp[newMask][j]=min(dp[newMask][j],dp[mask][i]+cost[i][j]);
                }
            }
        }

        int ans=INF;
        
        for(int i=0;i<n;i++){
            ans=min(ans,dp[(1<<n)-1][i]+cost[i][0]);
        }
        
        return ans;
    }
};
