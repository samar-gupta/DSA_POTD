//Company Tags  : Amazon (Need to double confirm on this)
//Leetcode Link : https://leetcode.com/problems/reverse-prefix-of-word/

//Using simple loop and swap
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
        int j = word.find(ch);
        
        while(i < j) {
            swap(word[i], word[j]);
            i++;
            j--;
        }
        
        return word;
        
    }
};



//Using Library Functions
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string reversePrefix(string word, char ch) {
        reverse(begin(word), word.begin()+word.find(ch)+1);
        return word;
        
    }
};
