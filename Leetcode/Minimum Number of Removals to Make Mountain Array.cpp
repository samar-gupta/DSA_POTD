//Leetcode Link : https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/

//Approach-1 : (Using Bottom-Up LIS & LDS)  (as Bottom-Up LIS has stored values in DP Array)
//total elements in left side for LIS[i] = (i+1)   and  total ele. in Right Side for LDS[i] = (n-i)
//no. of  removal in LEFT Side = {(i+1) - LIS[i]}
//no. of removal in RIGHT Side = {(n-i) - LDS[i]}
//total removal = LEFT SIDE + RIGHT SIDE = {(i+1) - LIS[i]} + {(n-i) - LDS[i]}
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> LIS(n, 1);
        vector<int> LDS(n, 1);
        
        //calculate LIS
        for(int i = 0; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }
            
        //calculate LDS
        for(int i = n-1; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                if (nums[i] > nums[j]) {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }
            
        int minRemovals = n;    //max n removal in worst case
            
        for(int i = 0; i < n; i++) { //treat each element as Peak and find removal
            if (LIS[i] > 1 && LDS[i] > 1) //mountain array minimum length tabhi >= 3 aa paega
                minRemovals = min(minRemovals, n - LIS[i] - LDS[i] + 1);       //simplied formula converted from  =>  {(i+1) - LIS[i]} + {(n-i) - LDS[i]}
        }
            
        return minRemovals;
    }
};
