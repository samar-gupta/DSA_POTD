//Same question as (Leetocode-976. Largest Perimeter Triangle)
//Approach-1 : (Sorting)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
  public:
    int maxPerimeter(vector<int> &nums) {
        // code here.
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        
        for(int i = n-3; i>=0; i--) {
            //nums[i] < nums[i+1] < nums[i+2]
            
            if(nums[i] + nums[i+1] > nums[i+2]) //a + b > c
                return nums[i] + nums[i+1] + nums[i+2];
        }
        
        return -1;
    }
};
