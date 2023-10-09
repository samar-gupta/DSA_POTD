//Approach-1 (Using Two Custom Binary Search)
//T.C : O(nlogn)
class Solution {
public:

    int findLeftMost(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int left_most = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) {
                left_most = mid; //possibly my answer
                r = mid-1;     //but lets look at left more
            } else if(nums[mid] > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return left_most;
    }
    
    int findRightMost(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int right_most = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) {
                right_most = mid; //possibly my answer
                l = mid+1;   //but lets look at right more
            } else if(nums[mid] > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return right_most;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int l = findLeftMost(nums, target);
        int r = findRightMost(nums, target);
        
        return {l, r};
    }
};



//Approach-2 (Using C++ STL)
//T.C : O(nlogn)
class Solution {
public:
    
    vector<int> search_stl(vector<int>& nums, int target) {
      
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();              //first element equal to or greater than target
      
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();              //first element greater than target

        if(l == nums.size() || nums[l] != target) {                     //Why do we need this (nums[l] != target) ? ,Because lower_bound returns first element which is equal or GREATER THAN target. So, in case the target is not in the list, it will return first greater element than target which will be wrong
            return {-1, -1};
        }
      
        return {l, r-1};
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return search_stl(nums, target); 
    }
};
