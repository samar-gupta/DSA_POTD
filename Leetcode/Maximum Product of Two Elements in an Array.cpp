//Leetcode Link : https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/

//Approach-1 : 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = 0;
        int sec_largest = 0;
        
        for(int &num: nums) {
            if(num > largest) {
                sec_largest = largest;
                largest = num;
            } else {
                sec_largest = max(sec_largest, num);
            }
        }
        
        return (largest-1) * (sec_largest-1);
    }
};
