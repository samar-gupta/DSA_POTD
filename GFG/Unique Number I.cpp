class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
        int ans = 0 ;
        for(int a : arr)
            ans ^= a;        //xor of same element is zero
        return ans;          //remaining is answer 
    } 
};
