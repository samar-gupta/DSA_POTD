//Leetcode Link : https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/

//Approach-1 : 
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        //We can use an unordered_set or unordered_map as well
        
        int arr[1001] = {0};
        
        for(int &num: nums) { 
            arr[num]++;
        }
        while(original <= 1000 && arr[original] != 0) { 
            original *= 2; 
        }

        return original;
    }
};
