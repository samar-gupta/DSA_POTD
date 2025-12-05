//Leetcode Link : https://leetcode.com/problems/count-partitions-with-even-sum-difference

//Approach-1 (Using cumulative sum)
//T.C : O(n) ( 2 Pass  )
//S.C : O(1)
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(begin(nums), end(nums), 0);

        int leftSum = 0;
        int result = 0;
        
        for(int i = 0; i < n-1; i++) {
            leftSum      += nums[i];
            int rightSum = sum - leftSum;

            if((leftSum - rightSum)%2 == 0)
                result++;
        }

        return result;
    }
};



//Approach-2 (Using one pass - Maths)
//T.C : O(n) ( 1 Pass  )
//S.C : O(1)
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(begin(nums), end(nums), 0);

        if(sum % 2 == 0)
            return n-1; //all partitions will be possible as it only depends on sum
        
        return 0;
    }
};
