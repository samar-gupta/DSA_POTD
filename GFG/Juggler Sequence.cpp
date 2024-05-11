class Solution {
  public:
    vector<int> jugglerSequence(int n) {
        // code here
        vector<long long>ans={n};
        long long prev=n;
        while(prev!=1){
            if(prev%2==1){
                ans.push_back(sqrt(pow(prev,3)));
            }
            else{
                ans.push_back(sqrt(prev));
            }
            
            prev=ans.back();
            
        }
        return ans;
    }
};
