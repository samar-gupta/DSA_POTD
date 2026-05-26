//Leetcode Link : https://leetcode.com/problems/count-the-number-of-special-characters-i/description/

//Approach-1 (Frequency Count using ASCII index)
//T.C: O(n) 2 Pass
//S.C: O(1) fixed size array of 123
class Solution {
public:
    
    int numberOfSpecialChars(string word) {
        int freq[123] = {0};
        
        for(char ch: word) {
            freq[ch]++;
        }
        
        int count = 0;
        //ASCII: a: 97, b = 98 ..... 122: z
        //ASCII: A: 65, B = 66 ..... 90: Z
        
        for(int i = 97; i <= 122; i++) { //Iterate from 97 to 122 or 'a' to 'z'
            
            int capitalIndex = i - 32; //A... Ζ
            
            if(freq[i] > 0 && freq[capitalIndex] > 0) //Both should be present
                count++;
        }
        
        return count;
    }
};



//Approach-2 (Frequency Count using char iteration)
//T.C: O(n) 2 Pass
//S.C: O(1) fixed size array of 123
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int freq[123] = {0};
        
        for(char ch: word) {
            freq[ch]++;
        }
        
        int count = 0;
        //ASCII: a: 97, b = 98 ..... 122 : z
        //ASCII: A: 65, B = 66 ..... 90 : Z
        
        for(char ch = 'a'; ch <= 'z'; ch++) { //Iterate from 97 to 122 or 'a' to 'z'
            char capital = ch - 'a' + 'A'; //A... Z
            
            if(freq[ch] > 0 && freq[capital] > 0) //Both should be present
                count++;
        }
        
        return count;
    }
};



//Approach-3 (One Pass Frequency Count)
//T.C: O(n) 1 Pass
//S.C: O(1) fixed size array of 123
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int freq[123] = {0};
        int count = 0;
        
        for(char ch: word) {
            freq[ch]++;
            
            // Current ch is lower case, then look for upper case
            if(ch >= 'a' && ch <= 'z') {
                char capital = ch - 'a' + 'A';
                if(freq[ch] == 1 && freq[capital] > 0) // lowercase just appeared for first time
                    count++;
            } else { // Current ch is upper case, then look for lower case
                char lower = ch - 'A' + 'a';
                if(freq[ch] == 1 && freq[lower] > 0) // uppercase just appeared for first time
                    count++;
            }
        }
        
        return count;
    }
};
