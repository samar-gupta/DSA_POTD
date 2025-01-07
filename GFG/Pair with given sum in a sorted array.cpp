//Approach-1 : 
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        unordered_map<int, int> mp;
        int count = 0;
        
        for (int i = 0; i < arr.size(); i++) 
        {
            int cp = target - arr[i];
            if (mp.find(cp) != mp.end()) 
            {
                count += mp[cp];
            }
            mp[arr[i]]++;
        }
        
        return count;
    }
};
