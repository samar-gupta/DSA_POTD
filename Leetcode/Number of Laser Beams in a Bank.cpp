/*
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
*/

/****************************************************** C++ ******************************************************/
//Approach (Simple iterate and count)
//T.C : O(m*n) - Total number of characters in all string
//S.C : O(1)
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        
        int prev = 0;     //prevDeviceCount
        int result = 0;
        
        for(int i = 0; i < n; i++) {
            
            int curr = 0;                 //currDeviceCount
            for(char &ch : bank[i]) {
                if(ch == '1') curr++;
            }
            
            result += (prev * curr);
            
            if(curr != 0) {
                prev = curr;
            }
            
        }
        
        return result;
    }
};
