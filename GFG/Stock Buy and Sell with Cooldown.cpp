//Approach-1 : (using a dynamic programming approach with space optimization for maximum profit)
/*
  This code uses three states to track the maximum profit on any day: 
    held: profit when holding a stock,
    sold: profit when selling the stock on that day,
    rest: profit during cooldown or doing nothing.
  Transitions ensure cooldown day after selling before buying again, achieving the maximum possible profit
*/
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        // code here
        int n = prices.size();
        if (n == 0) return 0;

        int sold = 0;        // Max profit when last action is sell
        int held = -prices[0]; // Max profit when last action is buy (holding a stock)
        int rest = 0;        // Max profit when in cooldown/rest

        for (int i = 1; i < n; i++) {
            int prev_sold = sold;

            // If we sell today, previous must be holding a stock
            sold = held + prices[i];

            // If we buy today, previous must be cooldown state
            held = max(held, rest - prices[i]);

            // Rest is max of previous rest or previous sold (cooldown after selling)
            rest = max(rest, prev_sold);
        }

        // Maximum profit will be max of sold and rest on last day (can't end holding)
        return max(sold, rest);
    }
};
