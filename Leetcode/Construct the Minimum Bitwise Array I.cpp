//Leetcode Link : https://leetcode.com/problems/construct-the-minimum-bitwise-array-i
//PART - II     : https://github.com/samar-gupta/DSA_POTD/blob/main/Leetcode/Construct%20the%20Minimum%20Bitwise%20Array%20II.cpp

//Approach (Brute Force All Possible Answers)
//T.C : O(n * m), m = maximum number in nums
//S.C : O(1)
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;

        for(int &num : nums) {

            bool found = false;
            for(int x = 0; x < num; x++) {
                if((x | (x+1)) == num) {
                    result.push_back(x);
                    found = true;
                    break;
                }
            }
            if(!found)
                result.push_back(-1);

        }

        return result;
    }
};
