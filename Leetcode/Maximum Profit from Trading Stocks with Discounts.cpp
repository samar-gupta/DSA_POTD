//Leetcode Link : https://leetcode.com/problems/maximum-profit-from-trading-stocks-with-discounts

//Approach (DFS + Recursion)
//T.C : O(n * budget^2)
//S.C : O(n * budget)
class Solution
{
public:
    void DFS(
        int u,
        const vector<int>& present,
        const vector<int>& future,
        unordered_map<int, vector<int>>& adj,
        vector<vector<vector<int>>>& statesProfit,
        int budget
    ) {
        // childrenStatesProfit:
        // first  -> child profit if parent NOT bought
        // second -> child profit if parent IS bought
        vector<pair<vector<int>, vector<int>>> childrenStatesProfit;

        //Process children first
        for (int v : adj[u]) {
            DFS(v, present, future, adj, statesProfit, budget);
            childrenStatesProfit.push_back({statesProfit[v][0], statesProfit[v][1]});
        }

        // parentBought = 0 or 1
        for (int parentBought = 0; parentBought <= 1; ++parentBought) {

            int price  = (parentBought == 1) ? present[u] / 2 : present[u];
            int profit = future[u] - price;
            
            vector<int> bestProfitAtU(budget + 1, 0);

            // Case 1: Do NOT buy node u
            vector<int> childrenProfitIfUNotBought(budget + 1, 0);

            for (const auto& child : childrenStatesProfit) { //from all child
                vector<int> temp(budget + 1, 0);

                for (int used = 0; used <= budget; ++used) { 
                    for (int take = 0; used + take <= budget; ++take) { 
                        temp[used + take] = max(temp[used + take], childrenProfitIfUNotBought[used] + child.first[take]);
                    }
                }
                childrenProfitIfUNotBought = move(temp);
            }

            for (int b = 0; b <= budget; ++b) {
                bestProfitAtU[b] = max(bestProfitAtU[b], childrenProfitIfUNotBought[b]);
            }

            // Case 2: Buy node u
            if (price <= budget) {
                vector<int> childrenProfitIfUBought(budget + 1, 0);

                for (const auto& child : childrenStatesProfit) { //from all child
                    vector<int> temp(budget + 1, 0);

                    for (int used = 0; used <= budget; ++used) {
                        for (int take = 0; used + take <= budget; ++take) {
                            temp[used + take] = max(temp[used + take], childrenProfitIfUBought[used] + child.second[take]);
                        }
                    }
                    childrenProfitIfUBought = move(temp);
                }

                for (int b = price; b <= budget; ++b) {
                    bestProfitAtU[b] = max(bestProfitAtU[b], childrenProfitIfUBought[b - price] + profit);
                }
            }

            statesProfit[u][parentBought] = move(bestProfitAtU);
        }
    }

    int maxProfit(
        int n,
        vector<int>& present,
        vector<int>& future,
        vector<vector<int>>& hierarchy,
        int budget) {
        unordered_map<int, vector<int>> adj;
        for (auto& h : hierarchy) {
            int u = h[0]-1;
            int v = h[1]-1;
            adj[u].push_back(v);
        }

        //statesProfit[u][0][b] = profit at u when it's parent had not bought stock
        //statesProfit[u][1][b] = profit at v when it's parent bought had bought stock
        vector<vector<vector<int>>> statesProfit(n, vector<vector<int>>(2, vector<int>(budget + 1, 0)));

        DFS(0, present, future, adj, statesProfit, budget);

        int ans = 0;
        for (int b = 0; b <= budget; ++b) {
            ans = max(ans, statesProfit[0][0][b]);
        }
        return ans;
    }
};
