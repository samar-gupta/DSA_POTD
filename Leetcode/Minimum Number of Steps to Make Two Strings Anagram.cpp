//Leetcode Link    : https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
//Company Tags     : Google

//Approach - (Storing difference of frequencies of characters from both strings in one map)
//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();
        
        int mp[26] = {0};
        
        for(int i = 0; i<n; i++) {
            mp[s[i] - 'a']++;
            mp[t[i] - 'a']--;
        }

        int result = 0;

        for(int i = 0; i < 26; i++) {
            result += max(0, mp[i]);
        } 
        
        return result;
    }
};






//Approach - 1 (Using two map to store frequencies of characters in both strings)
//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();
        
        int mp_s[26] = {0};
        int mp_t[26] = {0};
        
        for(int i = 0; i<n; i++) {
            mp_s[s[i] - 'a']++;
            mp_t[t[i] - 'a']++;
        }
        
        int result = 0;
        
        for(int i = 0; i < 26; i++) {
            int freq_in_t = mp_t[i];
            
            int freq_in_s = mp_s[i];
            
            if(freq_in_t < freq_in_s) {
                result += freq_in_s - freq_in_t;
            }
        } 
        
        return result;
    }
};

