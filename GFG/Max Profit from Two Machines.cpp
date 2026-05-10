class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size();
        vector<pair<int, int>> arr;
        
        for (int i = 0; i < n; i++)
        {
            arr.push_back({abs(a[i] - b[i]), i});
        }
        
        sort(arr.begin(), arr.end(),
             greater<pair<int, int>>());
             
        int ans = 0;
        
        int cntA = 0;
        int cntB = 0;
        
        for (auto &it : arr) 
        {
            int i = it.second;
            if (a[i] >= b[i]) 
            {
                if (cntA < x) 
                {
                    ans+= a[i];
                    cntA++;
                }
                else 
                {
                    ans+= b[i];
                    cntB++;
                }
            }
            else
            {
                if (cntB < y)
                {
                    ans+= b[i];
                    cntB++;
                }
                else
                {
                    ans+= a[i];
                    cntA++;
                }
            }
        }
        
        return ans;
    }
};
