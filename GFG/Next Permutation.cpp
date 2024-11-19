//Approach-1 : (Using C++ STL)
class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        // using inbulit function
        next_permutation(arr.begin(),arr.end());
    }
};


//Approach-2 :
class Solution {
  public:
    void nextPermutation(vector<int>& nums) {
        // code here
        int n=nums.size();
        int peak=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                peak=i;
                break;
            }
        }
        
        if(peak==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(int i=n-1;i>peak; i--){
            if(nums [peak]<nums[i]){
                swap(nums [peak], nums[i]);
                break;
            }
        }
        
        reverse(nums.begin()+peak+1,nums.end());
        return;
    }
};
