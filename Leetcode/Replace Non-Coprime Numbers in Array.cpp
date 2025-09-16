//Leetcode Link : https://leetcode.com/problems/replace-non-coprime-numbers-in-array

//Approach (Using vector as a stack)
//T.C : O(n * log(x)), where log comes from GCD
//S.C : O(1)
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result; //or you can use a stack

        //Processing left to right
        for(int num : nums) {

            while(!result.empty()) {
                int prev = result.back();
                int curr = num;

                int GCD = gcd(prev, curr);
                if(GCD == 1) {
                    break;
                }

                result.pop_back();
                int LCM = prev / GCD * curr;

                num = LCM; //merged number
            }
            result.push_back(num); //merged num put back to result
        }
        return result;
    }
};
