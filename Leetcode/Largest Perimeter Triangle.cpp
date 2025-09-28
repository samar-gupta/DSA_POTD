//Company Tags  : C3.ai
//Leetcode Link : https://leetcode.com/problems/largest-perimeter-triangle/

//Approach-1 : (Brute Force)
//T.C : cubic or qudratic 


//Approach-2 : (Sorting)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        
        for(int i = n-3; i>=0; i--) {
            //nums[i] < nums[i+1] < nums[i+2]
            
            if(nums[i] + nums[i+1] > nums[i+2]) //a + b > c
                return nums[i] + nums[i+1] + nums[i+2];
        }
        
        return 0;
        
    }
};
