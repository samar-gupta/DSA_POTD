class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> mp;
        for(int i:arr)
            mp[i]++;
            
        int count = 0;
        
        for(int i=0;i<arr.size();i++){
            if(mp[k + arr[i]])
                count += mp[k+arr[i]];
        }
        
        return count;
    }
};
