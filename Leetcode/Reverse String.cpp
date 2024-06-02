//Leercode Link : https://leetcode.com/problems/reverse-string/

//Approach-1
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int i = 0, j = n-1;
        
        while(i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};



//Approach-2
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(begin(s), end(s));
    }
};
