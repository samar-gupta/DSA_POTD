//Company Tags  : Amazon
//Leetcode Link : https://leetcode.com/problems/subarrays-with-k-different-integers/

//Approach-1 (Standard Sliding Window twice - A very good Pattern of Sliding Window Problems)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    
    //Total count of subarrays having <= k distict elements
    int slidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        int n = nums.size();
        int i = 0; 
        int j = 0;
        
        int count = 0;
        
        while(j < n) {
            
            mp[nums[j]]++;
            
            while(mp.size() > k) {
                //shrink the window
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            
            count += (j-i+1); //ending at j
            j++;
        }
        
        return count;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k-1);
    }
};



//Approach-2 (One Pass Flow)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        
        int i_chota  = 0;
        int j        = 0;
        int i_bada   = 0;
        
        int result   = 0;
  
        while(j < n) {
            mp[nums[j]]++;
            
            while(mp.size() > k) {
                mp[nums[i_chota]]--;
                if(mp[nums[i_chota]] == 0) {
                    mp.erase(nums[i_chota]);
                }
                i_chota++;
                i_bada = i_chota;
            }
            
            while(mp[nums[i_chota]] > 1) {
                mp[nums[i_chota]]--;
                i_chota++;
            }
            
            if(mp.size() == k) {
                result += i_chota - i_bada + 1;
            }
            j++;
        }
        
        return result;
    }
};
