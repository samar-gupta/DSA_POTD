//Leetcode Link : https://leetcode.com/problems/maximum-alternating-sum-of-squares

//Approach-1 (Square and sort and pick larger and smaller)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++ ){
            nums[i] = nums[i]*nums[i];
        }

        sort(begin(nums), end(nums));

        long long largeHalf = accumulate(begin(nums)+n/2, end(nums), 0LL);
        long long smallHalf = accumulate(begin(nums), begin(nums)+n/2, 0LL);

        return largeHalf - smallHalf;
    }
};


//Approach-2 (Square and partial-sort and pick larger and smaller)
//T.C : Average O(n) because of nth_element
//S.C : O(1)
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++ ){
            nums[i] = nums[i]*nums[i];
        }

        nth_element(begin(nums), begin(nums)+n/2, end(nums));

        long long largeHalf = accumulate(begin(nums)+n/2, end(nums), 0LL);
        long long smallHalf = accumulate(begin(nums), begin(nums)+n/2, 0LL);

        return largeHalf - smallHalf;
    }
};
