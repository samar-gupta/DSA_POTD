class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // code here
        vector<int>v;
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]]>0){
                continue;
            }
            else{
                v.push_back(arr[i]);
            }
            mp[arr[i]]++;
        }
        return v;
    }
};
