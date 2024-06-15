//Leetcode Link : https://leetcode.com/problems/ipo/description/

//Approach: (Using heap and greedily picking up projects) (sortong based on capital and using max-heap to store profits)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int findMaximizedCapital(int k, int paissa, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        vector<pair<int, int>> vec(n);
        
        for (int i = 0; i < n; i++) {
            vec[i] = {capital[i], profits[i]};
        }

        sort(vec.begin(), vec.end());

        int i = 0;

        priority_queue<int> pq;

        while (k--) {
            while (i < n && vec[i].first <= paissa) {
                pq.push(vec[i].second);
                i++;
            }
            if (pq.empty())
                break;
            paissa += pq.top();
            pq.pop();
        }
        return paissa;
    }
};
