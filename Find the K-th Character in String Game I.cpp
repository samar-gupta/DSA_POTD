//Leetcode Link : https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/description/

//Approach - Recursion
//T.C : O(log(k))
//S.C : O(log(k))) of system stack
class Solution {
public:
    char kthCharacter(int k) {
        if (k == 1) {
            return 'a';
        }

        int len = 1;          
        int newK;

        while(len < k) {
            len *= 2;               
            if (len >= k) {         
                newK = k - len / 2;      
                break;                   
            }
        }

        char res = kthCharacter(newK);

        if (res == 'z') 
            return 'a'; 

        return res + 1;
    }
};
