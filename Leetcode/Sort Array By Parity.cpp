/*
      Company Tags                : META
      Leetcode Link               : https://leetcode.com/problems/sort-array-by-parity/
*/

/************************************************************ C++ ************************************************************/


// Approach-1 (Using simple iteration)
// T.C : O(n)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = 0;
        
        for(int i = 0; i<nums.size(); i++) {
            
            if(nums[i]%2 == 0) {//even
                swap(nums[i], nums[j]);
                j++;
            }
        }
        
        return nums;
    }
};




// Approach-2 (Writing your own custom comparator for sorting)
class Solution {
public:
    
    static bool comparator(int a, int b) {
        return a%2 < b%2; //a%2 will be 0 if it's even and since we do a%2 < b%2, hence a will come first if it's even
    }
    
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(begin(nums), end(nums), comparator);
        
        return nums;
    }
};
