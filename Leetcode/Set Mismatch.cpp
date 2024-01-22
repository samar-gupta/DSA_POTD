//Company tags    : Amazon
//Leetcode Link   : https://leetcode.com/problems/set-mismatch/

//Approach-1 (Smart Approach)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        
        int dup     = -1;
        int missing = -1;
        
        for(int i = 0; i<n; i++) {
            int num = abs(nums[i]);
            
            if(nums[num-1] < 0)
                dup = num;
            else
                nums[num-1] *= (-1);
        }
        
        for(int i = 0; i<n; i++) {
            if(nums[i] > 0) {
                missing = i+1;
                break;
            }
        }
        
        return {dup, missing};
    }
};





//Approach-2 (Basic Approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int miss = 0, dup = 0;
        
        map<int, int> mp;
        for(int x:nums) {
            mp[x]++;
        }
        
        for(int i = 1; i<=n; i++) {
            if(mp.count(i)) {
                if(mp[i] == 2)
                    dup = i;
            } else
                miss = i;
        }
        
        return {dup, miss};
    }
};
