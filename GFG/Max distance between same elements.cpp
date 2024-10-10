class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        unordered_map<int,int>mp;
        int ans=INT_MIN;
        
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i])!=mp.end()) { 
                ans=max(ans,i-mp[arr[i]]);  
            } else {
                mp[arr[i]]=i; 
            }
        }
      
      return ans;
    }
};
