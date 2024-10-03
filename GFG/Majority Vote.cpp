class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int n=nums.size();
        int cnt=1;
        vector<int>v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                cnt++;
            }
            else{
                if(cnt>(n/3)){
                    v.push_back(nums[i]);
                }
                cnt=1;
            }
        }
        if(cnt>(n/3)){
            v.push_back(nums[n-1]);
        }
        if(v.size()==0){
            return {-1};
        }
        else{
            return v;
        }
    }
};
