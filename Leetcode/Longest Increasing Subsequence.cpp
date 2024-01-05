//Company Tags  : Microsoft
//Approach - (Using concept of Patience Sorting (O(nlogn))
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted;
        
        for(int i = 0; i<n; i++) {
            /*
			     Why lower bound ?
				 We want increasing subsequence and  hence 
				 we want to eliminate the duplicates as well.
				 lower_bound returns iterator to "next greater or equal to"
			*/
            auto it = lower_bound(begin(sorted), end(sorted), nums[i]);
            
            if(it == end(sorted))
                sorted.push_back(nums[i]); //greatest : so insert it
            else
                *it = nums[i]; //replace
        }
        
        return (int)sorted.size();
    }
};
