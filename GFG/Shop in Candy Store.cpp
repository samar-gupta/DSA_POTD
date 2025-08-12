//Approach-1 : (Using Sorting)
//T.C : Onlogn)
//S.C : O(1)
class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        int n=prices.size();
        int i=0;
        int j=n-1;
        
        sort(prices.begin(),prices.end());
        
        int minmoney=0;
        int maxmoney=0;
        int candies=0;
        while(candies<n){
            minmoney+=prices[i];
            maxmoney+=prices[j];
            
            i++;
            j--;
            
            candies=candies+1+k;
        }
        
        return {minmoney,maxmoney};
    }
};
