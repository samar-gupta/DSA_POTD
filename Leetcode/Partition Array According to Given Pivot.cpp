//Leetcode Link : https://leetcode.com/problems/partition-array-according-to-given-pivot

//Approach-1 (Using extra space of 3 vectors)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> lessPivot;
        vector<int> equalPivot;
        vector<int> greaterPivot;

        for(int i = 0; i < n; i++) {
            if(nums[i] < pivot) {
                lessPivot.push_back(nums[i]);
            } else if(nums[i] == pivot) {
                equalPivot.push_back(nums[i]);
            } else {
                greaterPivot.push_back(nums[i]);
            }
        }

        for(int &num : equalPivot) {
            lessPivot.push_back(num);
        }

        for(int &num : greaterPivot) {
            lessPivot.push_back(num);
        }

        return lessPivot;

    }
};


//Approach-2 (Using pointers only)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        int countless  = 0;
        int countequal = 0;

        for(int &num : nums) {
            if(num < pivot)
                countless++;
            else if(num == pivot)
                countequal++;
        }

        int i = 0; //less than pivot
        int j = countless; //equal to pivot
        int k = countless + countequal; //more than pivot
        vector<int> result(n);

        for(int &num : nums) {
            if(num < pivot) {
                result[i] = num;
                i++;
            } else if(num == pivot) {
                result[j] = num;
                j++;
            } else {
                result[k] = num;
                k++;
            }
        }
        
        return result;

    }
};


//Approach-3 (Using pointers only)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> result(n);

        //original nums
        int i = 0;
        int j = n-1;

        //result variables
        int i_ = 0;
        int j_ = n-1;

        while(i < n && j >= 0) {
            if(nums[i] < pivot) {
                result[i_] = nums[i];
                i_++;
            }

            if(nums[j] > pivot) {
                result[j_] = nums[j];
                j_--;
            }

            i++;
            j--;
        }

        //i_ to j_ -> fill the pivot
        while(i_ <= j_) {
            result[i_] = pivot;
            i_++;
        }

        return result;

    }
};
