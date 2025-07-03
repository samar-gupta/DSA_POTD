//Leetcode Link : https://leetcode.com/problems/find-the-k-th-character-in-string-game-i

//Approach-1 (Simulation)
//T.C : O(k)
//S.C : O(k)
class Solution {
public:

    char kthCharacter(int k) {
        int idx = k-1;
        string result = "a";

        while(result.length() < k) {
            int n = result.length();
            for(int i = 0; i < n; i++) {
                char ch = result[i] == 'z' ? 'a' : result[i]+1;
                result.push_back(ch);
            }
        }

        return result[idx];
    }
};


//Approach-2 (bit observation to find shift)
//T.C : O(log(k-1))
//S.C : O(1)
class Solution {
public:
    char kthCharacter(int k) {
        int shift = __builtin_popcount(k-1);

        return 'a' + shift;
    }
};


//from Leetcode Qn. : 3307. Find the K-th Character in String Game II
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
