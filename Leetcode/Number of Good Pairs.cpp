// Approach-4
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int i=0, j=i+1, count = 0;
        
        while(i != n-1) {
            if(nums[i] == nums[j]) count++;
            j++;
            
            if(j == n) {
                i++;
                j = i+1;
            }
        }
        return count;
    }
};




//Approach-1 (Using simple double for loop and counting good pairs)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for(int i = 0; i<n-1; i++) {
            
            for(int j = i+1; j<n; j++) {
                if(nums[j] == nums[i]) {
                    count++;
                }
            }
        }
        
        return count;
    }
};




//Approach-2 (Using hashmap)
//T.C : O(n) - Two Times Traversing
//S.C : O(1)

// So generalising for n occurrences, total = (n-1) + (n-2) + ..... + 1 , i.e. Sum of 1st (n-1) natural numbers = (n-1) * (n-1+1)/2 = ((n-1) * n / 2 = n*(n-1)/2

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> mp;
        
        for(int &num : nums) {
            mp[num]++;
        }
        
        for(auto &it : mp) {
            int count = it.second;
            result += (count * (count-1))/2;          
            
        }
        return result;
    }
};




//Approach-3 (Using hashmap)
//T.C : O(n) - One Time Traversing
//S.C : O(1)
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {   
        int n = nums.size();
        int result = 0;
        
        unordered_map<int, int> mp;
        
        for(int &num : nums) {
            result += mp[num];             // result += mp[num]++;
            mp[num]++;
        }
        return result;
    }
};
