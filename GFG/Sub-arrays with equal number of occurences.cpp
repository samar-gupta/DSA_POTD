class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        // code here
        int count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int x_count = 0;
        int y_count = 0;
        
        for (int &num : arr)
        {
            if (num == x)
                x_count++;
            if (num == y)
                y_count++;
                
            int diff = x_count - y_count;
            
            if (mp.find(diff) != mp.end())
            {
                count += mp[diff];
            }
            
            mp[diff]++;
        }
        
        return count;
    }
};
