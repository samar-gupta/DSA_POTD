class Solution {
  public:
    int vowelCount(string& s) {
        // code here
        unordered_map<int,int>mp;
        for(auto it:s){
            if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u'){
                mp[it]++;
            }
        }
        
        int fact=1;
        int n=mp.size();
        
        if(n==0) return 0;
        
        for(int i=1;i<=n;i++){
            fact*=i;
        }
        
        for(auto it: mp){
            fact*=it.second;
        }
        return fact;
    }
};
