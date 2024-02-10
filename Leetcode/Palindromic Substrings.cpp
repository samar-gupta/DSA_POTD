//Company Tags    : GOOGLE
//Leetcode Link   : https://leetcode.com/problems/palindromic-substrings/description

//Approach-1 (Simply check all substrings possilbe)
//T.C : O(n^3)
//S.C : O(1)
class Solution {
public:

    bool check(string &s, int i, int j) {
        if(i>j) {
            return true;
        }

        if(s[i] == s[j]) {
            return check(s, i+1, j-1);
        }

        return false;
    }

    int countSubstrings(string s) {
        int n = s.length();

        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {         //check all possible substrings

                if(check(s, i, j)) {
                    count++;
                }

            }
        }

        return count;
    }
};





//Approach-2 (Memoize the approach above)
//T.C : O(n^2) - Every subproblem is being computed only once and after that it's being reused      //{O(n) for first time only then O(1), so O(n^3) ~ O(n^2)}
//S.C : O(n^2)
class Solution {
public:
    int t[1001][1001];
    bool check(string &s, int i, int j) {
        if(i >= j) {
            return true;
        }

        if(t[i][j] != -1) {
            return t[i][j];         //0 : False, 1 : True
        }

        if(s[i] == s[j]) {
            return t[i][j] = check(s, i+1, j-1);
        }

        return t[i][j] = false;
    }

    int countSubstrings(string s) {
        int n = s.length();

        memset(t, -1, sizeof(t));         //t[i][j] = -1 (not solved yet)  //t[i][j] = 0 False  //t[i][j] = 1 True

        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {       //check all possible substrings

                if(check(s, i, j)) {
                    count++;
                }

            }
        }

        return count;
    }
};





//Approach-3(Bottom Up - Blue Print of Pallindrome Qns)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();

        vector<vector<bool>> t(n, vector<bool>(n, false));       //STATE - t[i][j] = true : s[i:j] is a palindromic substring where i and j are inclusive indices

        int count = 0;

        for(int L = 1; L <= n; L++) {                //L - length

            for(int i = 0; i+L-1 < n; i++) {
                int j = i + L - 1;

                if(i == j) {                    //for length 1
                    t[i][j] = true;
                } else if(i + 1 == j) {               //for length 2 , as i = 2 -> j = 3 , i+1 = j
                    t[i][j] = (s[i] == s[j]);
                } else {                                      //for length >= 3 
                    t[i][j] = (s[i]==s[j] && t[i+1][j-1]);
                }

                if(t[i][j] == true) {
                    count++;
                }

            }

        }

        return count;
    }
};





//Approach-4 (Smart approach)
//T.C : O(n^2)
//S.C : o(1)
class Solution {
public:
    int count;

    void check(string &s, int i, int j, int n) {
        while(i >= 0 && j < n && s[i] == s[j]) {
            count++;
            i--;                                     //expanding from center    <-- i
            j++;                                     //expanding from center           j -->
        }
    }

    int countSubstrings(string s) {
        int n = s.length();
        count = 0;

        for(int i = 0; i < n; i++) {
            check(s, i, i, n);                //Every single character in the string is a center for possible odd-length palindromes: check(s, i, i)
            check(s, i, i+1, n);             //Every pair of consecutive characters in the string is a center for possible even-length palindromes: check(s, i, i+1)
        }

        return count;
    }
};
