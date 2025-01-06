class Solution {
  public:
    vector<int> sumClosest(vector<int>& nums, int target) {
        // code here
        if(nums.size()<2)
            return {};
            
        sort(nums.begin(),nums.end());
        
        int sum=nums[0]+nums[1];
        int diff=INT_MAX;
        int a=nums[0],b=nums[1];
        
        int start=0,end=nums.size()-1;
            
        while(start<end){
            int currSum=nums[start]+nums[end];
            
            if(currSum==target)
                return {nums[start],nums[end]};
                
            int currDiff=abs(currSum-target);
            
            if(currDiff<diff){
                sum=currSum;
                diff=currDiff;
                a=nums[start],b=nums[end];
            }
            
            if(currSum>target)
                end--;
            else
                start++;
        }
        
        return {a,b};
    }
};
