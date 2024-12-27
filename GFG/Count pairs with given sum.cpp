class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        int n=arr.size();
        unordered_map<int, int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int req=target-arr[i];
            if(mp.find(req)!=mp.end()){
                if(arr[i]==req){
                    ans+=mp[req]-1;
                }
                else ans+=mp[req];
                mp[arr[i]]--;
                if(mp[arr[i]]==0) mp.erase(arr[i]);
            }
        }
        return ans;
    }
};
