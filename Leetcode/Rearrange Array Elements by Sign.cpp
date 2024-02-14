//Leetcode Link  : https://leetcode.com/problems/rearrange-array-elements-by-sign/

//T.C : O(n)
//S.C : O(n) for result
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pi = 0; //positive index
        int ni = 1; //negative index
        
        vector<int> result(n);
        
        for(int &num : nums) {
            if(num > 0) {
                result[pi] = num;
                pi +=2;
            } else {
                result[ni] = num;
                ni += 2;
            }
        }
        
        return result;   
    }
};
