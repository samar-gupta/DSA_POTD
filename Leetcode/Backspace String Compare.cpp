/*
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/backspace-string-compare/
*/

/******************************************************** C++ ********************************************************/
//Approach-1 (Using extra space)
//T.C : O(n+m)
//S.C : O(m+n)
class Solution {
public:
    string buildString(string &s) {
        int n = s.length();
        string temp = "";

        for(int i=0; i<n; i++) {
            if(s[i] != '#') 
                temp.push_back(s[i]);
            else if(!temp.empty())                  // temp.lenghth() > 0
                temp.pop_back();
        }

        return temp;
    }

    bool backspaceCompare(string s, string t) {
        return buildString(s) == buildString(t);
    }
};



//Approach-2 (Using O(1) space)
//T.C : O(max(m, n))
//S.C : O(1)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m = s.length();
        int n = t.length();

        int i = m-1, j = n-1;
        int skip_s = 0;
        int skip_t = 0;

        while(i >= 0 || j >= 0) {

            while(i >= 0) {
                if(s[i] == '#') {
                    skip_s++;
                    i--;
                } else if(skip_s > 0) {
                    skip_s--;
                    i--;
                } else {
                    break;
                }
            }

            while(j >= 0) {
                if(t[j] == '#') {
                    skip_t++;
                    j--;
                } else if(skip_t > 0) {
                    skip_t--;
                    j--;
                } else {
                    break;
                }
            }

            char first = i < 0 ? '$' : s[i];
            char second = j < 0 ? '$' : t[j];

            if(first != second)
                return false;

            i--;
            j--;
        }

        return true;
    }
};
