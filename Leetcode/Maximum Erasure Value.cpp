//Leetcode Link : https://leetcode.com/problems/maximum-erasure-value/

//Approach-1 (Sliding Window)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        int i = 0;
        int j = 0;
        int sum = 0;
        int result = 0;

        while(j < n) {
            if(!st.count(nums[j])) {
                sum += nums[j];
                result = max(result, sum);
                st.insert(nums[j]);
                j++;
            } else {
                while(i < n && st.count(nums[j])) {
                    sum -= nums[i];
                    st.erase(nums[i]);
                    i++;
                }
                
            }
        }

        return result;
    }
};



//Approach-2 (Using cumulative sum to find subarray sum)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> cus(n, 0);
        cus[0] = nums[0];
        for(int i = 1; i < n; i++)
            cus[i] = cus[i-1] + nums[i];
        
        vector<int> mp(10001, -1); //Using as a map 1 <= nums[i] <= 10^4
        int maxS   = 0;
        int i      = 0;
        int j      = 0;
        
        while(j < n) {
            i       = max(i, mp[nums[j]]+1);
            int jthSum  = cus[j];
            int ithSum  = i-1 < 0 ? 0 : cus[i-1];
            maxS        = max(maxS, jthSum - ithSum);
            mp[nums[j]] = j;

            j++;
        }
        
        return maxS;
    }
};
