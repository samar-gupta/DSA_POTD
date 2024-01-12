//Leetcode Link  : https://leetcode.com/problems/determine-if-string-halves-are-alike/
//Company Tags   : Google, Amazon, Microsoft, Meta
//T.C - O(n)
//S.C - O(1)
class Solution {
public:
    bool isVowel(char &ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
    
    bool halvesAreAlike(string s) {
        int n = s.length();
        
        int mid = n/2;
        
        int i = 0, j = mid;
        
        int countL = 0;
        int countR = 0;
        
        while(i < n/2 && j < n) {
            
            if(isVowel(s[i])) countL++;
            if(isVowel(s[j])) countR++;
            
            i++;
            j++;
        }
        
        return countL == countR;
    }
};






//Approach - (Using Set)
//T.C - O(n)
//S.C - O(n)
class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        
        int mid = n/2;
        
        int i = 0, j = mid;
        
        int countL = 0;
        int countR = 0;
        
        string vowels = "aeiouAEIOU";
        unordered_set<char> st(begin(vowels), end(vowels));
        
        while(i < n/2 && j < n) {
        
            if(st.find(s[i]) != st.end()) countL++;
            if(st.find(s[j]) != st.end()) countR++;
            
            i++;
            j++;
        }
        
        return countL == countR;
    }
};
