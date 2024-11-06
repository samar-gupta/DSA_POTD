//Leetcode Link : https://leetcode.com/problems/find-if-array-can-be-sorted

//Approach-1 (Using Bubble Sort)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        bool swapped = true;

        for(int i = 0; i < n; i++) {
            swapped = false;

            for(int j = 0; j < n - i - 1; j++) { //in every pass, the max element bubbles up to right most index
                if(nums[j] <= nums[j+1]) { //no swap required
                    continue;
                } else { //pakka nums[j] > nums[j+1]
                    //swap is required
                    if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1])) {
                        swap(nums[j], nums[j+1]);
                        swapped = true;
                    } else {
                        //not able to swap, hence can't sort it
                        return false;
                    }
                }
            }

            if(swapped == false) { //no swapping was done in the pass, hence array was already sorted
                break; //no more passes are required
            }

        }

        return true;
    }
};



//Approach-2 (Using simple segment sorting check)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        //Current Segment
        int numOfSetBits = __builtin_popcount(nums[0]);
        int maxOfSegment = nums[0];
        int minOfSegment = nums[0];

        int maxOfPrevSegment = INT_MIN;

        for (int i = 1; i < nums.size(); i++) {
            if (__builtin_popcount(nums[i]) == numOfSetBits) { //they belong to same segment
                maxOfSegment = max(maxOfSegment, nums[i]); //find max of current segment
                minOfSegment = min(minOfSegment, nums[i]); //find min of current segment
            } else {  // Element belongs to a new segment
                
                if (minOfSegment < maxOfPrevSegment) { //ye bataya hai maine video me
                    return false;
                }

                // Update the previous segment's max
                maxOfPrevSegment = maxOfSegment;

                // new segment started now
                maxOfSegment = nums[i];
                minOfSegment = nums[i];
                numOfSetBits = __builtin_popcount(nums[i]);
            }
        }
        // Final check for proper segment arrangement
        if (minOfSegment < maxOfPrevSegment) {
            return false;
        }
        return true;
    }
};
