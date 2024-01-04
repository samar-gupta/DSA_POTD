//T.C : O(N)
//S.C : O(N)
class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        unordered_map<int,int>mp;
        for(int i=0;i<N;i++){
            mp[arr[i]]++;
        }
        int ans;
        for(auto i: mp){
            if(i.second==1){
                ans=i.first;
            }
        }
        return ans;
    }
};
