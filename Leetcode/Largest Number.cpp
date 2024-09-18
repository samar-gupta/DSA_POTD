//Company Tags  : Microsoft, Amazon, MakeMyTrip, Paytm, Zoho, Goldman Sachs
//Leetcode Link : https://leetcode.com/problems/largest-number/

//T.C : O(nlogn)
//S.C : O(1) (I am ignoring the space taken by result of size n which we have to return
class Solution {
public:
    static bool myFunction(int a, int b) {
        string s1 = to_string(a);
        string s2 = to_string(b);
        
        return (s1+s2) > (s2+s1);
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), myFunction);
        
        
        if(nums[0] == 0)
            return "0";
        string result = "";
        for(int i:nums)
            result += to_string(i);
        return result;
        
    }
};
