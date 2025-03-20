/*
Core Idea: We are allowed to do at most 2 transactions. Each transaction involves: Buy → Sell → Buy → Sell. The key challenge is that the second buy must happen after the first sell.
Variables Explained: int buy1 = INT_MAX, buy2 = INT_MAX, profit1 = 0, profit2 = 0;
buy1: Minimum price for the first buy, profit1: Maximum profit after first sell (first transaction completed) , buy2: Effective cost for the second buy, profit2: Maximum total profit after second sell (both transactions completed).
* Logic Step-by-Step:
 1. First transaction:
      buy1 = min(buy1, price[i]);
      profit1 = max(profit1, price[i] - buy1);
We keep track of the minimum price seen so far (buy1). Calculate max profit1 at every step (price[i] - buy1).

 2. Second transaction:
    buy2 = min(buy2, price[i] - profit1);
    profit2 = max(profit2, price[i] - buy2);
This part is the clever trick:
For second buy, instead of just taking price[i], we reduce the profit made from the first transaction.

Why?

Effectively, we are thinking:
"If I use the profit earned from the first transaction, the effective price I pay for the second stock reduces."
So, price[i] - profit1 represents the net cost after factoring in the first profit.
For each price, we update:
Effective buy cost (buy2).
Maximum total profit after second sell (profit2).
---

Why does this work?
It efficiently tracks:
1. First buy & sell → profit1.
2. Second buy (adjusted by profit1) & sell → profit2.

*/
//T.C - O(n)
//S.C : O(1)
class Solution {
  public:
    int maxProfit(vector<int> &price) {
        // code here
        int buy1 = INT_MAX, buy2 = INT_MAX, 
        profit1 = 0, profit2 = 0;
        for(int i = 0; i < price.size(); i++){
            buy1 = min(buy1, price[i]);
            profit1 = max(profit1, price[i] - buy1);
            buy2 = min(buy2, price[i] - profit1);
            profit2 = max(profit2, price[i] - buy2);
        }
        return profit2;
    }
};
