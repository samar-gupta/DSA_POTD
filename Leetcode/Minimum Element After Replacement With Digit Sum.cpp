//Leetcode Link : https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/description/

//Approach-1
//T.C: O(n * log10(m)), where n = nums.size(), m = max element in nums
//S.C: O(1)
class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        
        while(n > 0) {
            sum += n % 10; 
            n /= 10;
        }
        
        return sum;
    }
    
    int minElement(vector<int>& nums) {
        int result = 37; //Note that 1 <= nums[i] <= 10^4 and biggest sum can be obtained by 9999 (whose digit sum = 36)
        
        for(int num: nums) {
            int s = digitSum (num); //O(log10(num))
            
            result = min(result, s);
        }
        
        return result;
    }
};



//Approach-2
//T.C: O(n), where n = nums.size()
//S.C: O(1)
class Solution {
public:
    int digitSum(int n) {
        return
            (n / 10000) + // ten-thousands digit
            (n % 10000 / 1000) + // thousands digit
            (n % 1000 / 100) + // hundreds digit
            (n % 100 / 10) + // tens digit
            (n % 10); // units digit
    }
    
    int minElement(vector<int>& nums) {
        int result = 37; //Note that 1 <= nums[i] <= 10^4 and biggest sum can be obtained by 9999 (whose digit sum = 36)
        
        for(int num: nums) {
            int s = digitSum (num); //O(1)
            
            result = min(result, s);
        }
        
        return result;
    }
};
