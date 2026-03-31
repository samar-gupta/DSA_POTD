//Approach-1 :
class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int n=arr.size();
        int pbs=-1*arr[0];
        int pss=0;
        for(int i=1;i<n;i++)
        {
            //buy state
            int tbs=max(pbs,pss-arr[i]);

            //sell state
            int tss= max(pss, pbs+arr[i]-k);

            pbs=tbs;
            pss=tss;
        }

        return pss;
    }
};


//Approach-1 :
class Solution {
  public:
    int maxProfit(vector<int>& prices, int fee) {
        // Code here
        int hold = -prices[0], cash = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            hold = max(hold, cash - prices[i]);
            cash = max(cash, hold + prices[i] - fee);
        }
        
        return cash;
    }
};
