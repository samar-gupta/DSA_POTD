//Approach:
//Just store minimum and second minimum in each row 
//and move forward to caluculate the cost in the next row
class Solution {
  public:
    int minCost(vector<vector<int>> &costs) {
        // code here
        int n = costs.size();
        int k = costs[0].size();
        
        if(k <= 1 && n > 1)
            return -1;
        else if(k == 1 && n == 1)
            return costs[0][0];
        int min1 = 1e5 + 2, min2 = 1e5 + 2;
        for(int i = 0; i < k; i++)
        {
            if(min1 == 1e5 + 2)
                min1 = costs[0][i];
            else if(costs[0][i] <= min1)
            {
                min2 = min1;
                min1 = costs[0][i];
            }
            else if(costs[0][i] < min2)
            {
                min2 = costs[0][i];
            }
        }
        
        for(int i = 1; i < n; i++)
        {
            int newMin1 = INT_MAX, newMin2 = INT_MAX;
            for(int j = 0; j < k; j++)
            {
                if(costs[i - 1][j] == min1)
                {
                    costs[i][j] += min2;
                }
                else
                {
                    costs[i][j] += min1;
                }
                
                if(newMin1 == INT_MAX)
                    newMin1 = costs[i][j];
                    
                else if(costs[i][j] <= newMin1)
                {
                    newMin2 = newMin1;
                    newMin1 = costs[i][j];
                }
                else if(costs[i][j] < newMin2)
                {
                    newMin2 = costs[i][j];
                }
                    
            }
            min1 = newMin1;
            min2 = newMin2;
        }
        return min1;
    }
};
