//Leetcode Link : https://leetcode.com/problems/trionic-array-i

//Approach (Simply simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        int i = 0;

        //Increasing
        while(i+1 < n && nums[i] < nums[i+1])
            i++;

        if(i == 0 || i == n-1)
            return false;
        
        //Decreasing
        while(i+1 < n && nums[i] > nums[i+1])
            i++;
        
        if(i == n-1)
            return false;
        
        //Increasing
        while(i+1 < n && nums[i] < nums[i+1])
            i++;
        

        return i == n-1;
    }
};
