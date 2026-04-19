//Leetcode Link : https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/

//Approach (2 pointers)
//T.C : O(m+n)
//S.C : O(1)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int i = 0; //nums1
        int j = 0; //nums2

        int result = 0;

        while(i < m && j < n) {
            if(nums1[i] > nums2[j]) {
                i++;
            } else {
                result = max(result, j-i);
                j++;
            }
        }
        
        return result;
    }
};
