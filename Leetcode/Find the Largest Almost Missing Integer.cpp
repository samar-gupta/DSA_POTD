//Leetcode Link : https://leetcode.com/problems/find-the-largest-almost-missing-integer/description/

//Approach-1 : (Sliding Window)
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
         int n = nums.size();

    int i = 0;
    int j = 0;

    unordered_map<int, int> mp;
    //I will go to each subarray of size k (window of size k) and mark which element came in that subarray
    //In the end, I will see which element came in exactly 1 subarray

    unordered_set<int> st;
    while(j < n) {
        if(j-i+1 == k) { // k sized subarray

            //Collect which elements are in this window
            for(int l = i; l <= j; l++) {
                st.insert(nums[l]);
            }

            //Mark those elements
            for(int x : st) {
                mp[x]++;
            }

            st.erase(nums[i]); //shifting window
            i++;
        }
        j++;
    }

    int result = -1;

    //Find the largest element which appeared in one subarray only
    for(auto [num, count] : mp) {
        if(count == 1 && num > result) {
            result = num;
        }
    }

    return result;
    }
};


//Approach-2 : (Simple Observation) 
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

    //case 1 : When k == n
    if(k == n) { //only one subarray possible. Select the largest element
        return *max_element(begin(nums), end(nums));
    }

    //case 2 : When k == 1
    int freq[51] = {0};
    for(int &num : nums) {
        freq[num]++;
    }

    if(k == 1) { //every index is one subarray. Find largest element which appears only once
        for(int num = 50; num >= 0; num--) {
            if(freq[num] == 1) {
                return num;
            }
        }
        return -1;
    }

    //case 3 : 1 < k < n
    //Notice that only the first and last element are going to be the ones which will
    //appear only in one subarray. Others will be part of more than one subarray always

    int maxResult = -1;

    //So, if nums[0] appeared only at index 0, then it appeared only in one subarray
    if(freq[nums[0]] == 1) {
        maxResult = max(maxResult, nums[0]);
    }

    //Same, if nums[n-1] appeared only at index n-1, then it appeared only in one subarray
    if(freq[nums[n-1]] == 1) {
        maxResult = max(maxResult, nums[n-1]);
    }

    return maxResult;
    }
};
