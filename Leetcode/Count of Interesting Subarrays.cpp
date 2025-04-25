//Leetcode Link : https://leetcode.com/problems/count-of-interesting-subarrays/description/

//Approach (Using same concept as Leetcode - 974) - cumulative sum and modulo property
//T.C : O(n) //one pass without modifyung input 
//S.C : O(n)
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        int n = nums.size();

        unordered_map<int, long long> mp; //remainder -> count
        long long sum = 0; //sum will be equal to cnt of those elements % m == k

        long long result = 0;

        mp[0] = 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] % m == k)
                sum += 1;

            int r1 = sum%m;

            int r2 = (r1 - k + m) % m;

            result += mp[r2];
            mp[r1]++;
        }

        return result;
    }
};


//above is converted from this, T.C : Two pass, modifying input
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        
        // Convert array to 0s and 1s based on condition
        for(int i = 0; i < n; i++) {
            if(nums[i] % modulo == k) {
                nums[i] = 1;
            } else {
                nums[i] = 0;
            }
        }
        
        unordered_map<int, long long> mp;
        int sum = 0;
        long long result = 0;
        
        mp[0] = 1;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            
            int r1 = sum % modulo;
            
            int r2 = (r1 - k + modulo) % modulo;
            
            result += mp[r2];
            mp[r1]++;
        }
        
        return result;
    }
};
