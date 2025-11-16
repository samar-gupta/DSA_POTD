//Approach-1 : 
/*
  (Intuition) : 
      We want a subsequence that is common in both arrays strictly increasing
      We keep a 1-D array dp of size m.
          • dp[j] = length of the longest common increasing subsequence that ends at b[j].

      For each element of a (say a[i]):
          • We track the best LCIS seen so far among all b[j] that are smaller than a[i].
            This is stored in currMax.
          • If a[i] is equal to b[j], then the LCIS ending at b[j] becomes:
            currMax + 1
     At the end, we take the maximum value in dp.
*/
//TC : O(n × m)
//SC : O(m)
class Solution {
  public:
    int LCIS(vector<int> &a, vector<int> &b) {
        // code here
        int n=a.size();
        int m=b.size();
        
        vector<int> dp(m,0);  // dp[j] = LCIS ending at b[j]
        
        for(int i=0;i<n;i++){
            int currMax=0;
            
            for(int j=0;j<m;j++) {
                
                if(a[i]==b[j]){
                    dp[j]=currMax+1;
                }
                
                if(a[i]>b[j]){
                    currMax=max(currMax,dp[j]);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
