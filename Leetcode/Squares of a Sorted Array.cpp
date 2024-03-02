//Company Tags   : ByteDance
//Leetcode Link  : https://leetcode.com/problems/squares-of-a-sorted-array

//Approach-1
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            nums[i] = nums[i]*nums[i];
        }
        
        sort(begin(nums), end(nums)); //O(nlogn)
        return nums;
    }
};


//Approach-2 (Follow Up, without sorting nlogn)
//T.C : O(n)
//S.C : O(1) - (Not considering the space takent to store the result)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> result(n);
        
        int i = 0, j = n-1;
        int k = n-1;
        
        while(k >= 0) {
            int a = nums[i]*nums[i];
            int b = nums[j]*nums[j];
            
            if(a > b) {
                result[k] = a;
                i++;
            } else {
                result[k] = b;
                j--;
            }
            k--;
        }
        return result;
    }
};
