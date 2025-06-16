class Solution {
public:
    int getCost(vector<int>& heights, vector<int>& cost, int h) {
        int totalCost = 0;
        for (int i = 0; i < heights.size(); i++) {
            totalCost += abs(heights[i] - h) * cost[i];
        }
        return totalCost;
    }

    int minCost(vector<int>& heights, vector<int>& cost) {
        int lo = *min_element(heights.begin(), heights.end());
        int hi = *max_element(heights.begin(), heights.end());
        int ans = INT_MAX;

        while (lo <= hi) {
            int mid1 = lo + (hi - lo) / 3;
            int mid2 = hi - (hi - lo) / 3;

            int cost1 = getCost(heights, cost, mid1);
            int cost2 = getCost(heights, cost, mid2);

            ans = min({ans, cost1, cost2});

            if (cost1 < cost2) {
                hi = mid2 - 1;
            } else {
                lo = mid1 + 1;
            }
        }

        return ans;
    }
};
