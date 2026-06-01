//Leetcode Link : https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount

//Approach-1 (Sorting + Greedy Skip Every 3rd)
//T.C : O(n log n)
//S.C : O(1)
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(begin(cost), end(cost), greater<int>());

        int total = 0;

        for (int i = 0; i < n; i++) {
            if (i % 3 != 2)
                total += cost[i];
        }
        return total;
    }
};
