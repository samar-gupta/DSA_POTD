//Leetcode Link : 

//Approach-1 : 
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int n = bits.size();
        while(i < n){
            // If we are at the last index, it must be a one-bit character.
            if(i == n-1) return true;

            if(bits[i] == 0){
                // One-bit character
                i++;
            }else{
                // Two-bit character
                i += 2;
            }
        }

        return false;
    }
};
