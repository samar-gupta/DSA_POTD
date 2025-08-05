//Approach-1 : (using two pointer)
//T.C: O(n) 
//S.C: O(1)
//The isalnum() function in C++ is used to check whether 
//   a given character is alphanumeric, meaning it is either: 
//   a letter (A–Z or a–z) or a digit (0–9)
class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        int n = s.length();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;
            if (tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};
