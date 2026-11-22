//Leetcode Link : https://leetcode.com/problems/check-if-all-as-appears-before-all-bs

//Approach-1 (Adjacent pair check: look for "ba")
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool checkString(string s) {
        int n = s.length();

        for (int i = 1; i < n; i++) {
            if (s[i - 1] == 'b' && s[i] == 'a') 
                return false;
        }
        return true;
    }
};


//Approach-2 (Track last 'a' and first 'b' indices)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool checkString(string s) {
        int n = s.length();

        int first_b = -1;
        int last_a  = -1;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') {
                last_a = i;
            } else if(first_b == -1) {
                first_b = i;
            }
        }

        if(first_b == -1 || last_a == -1)
            return true;
        
        return last_a < first_b;
    }
};


//Approach-3 (Substring search for "ba")
//T.C : O(n)  (the pattern has constant length 2)
//S.C : O(1)
class Solution {
public:
    bool checkString(string s) {
        return s.find("ba") == string::npos;
    }
};


//Approach-4 (Check if string is sorted)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool checkString(string s) {
        return is_sorted(begin(s), end(s));
    }
};


//Approach-5 (Count 'a's, then verify prefix is all 'a')
//T.C : O(n)  (one pass to count + one pass to verify)
//S.C : O(1)
class Solution {
public:
    bool checkString(string s) {
        int count_a = count(begin(s), end(s), 'a');
        
        // the first count_a characters must all be 'a'
        for (int i = 0; i < count_a; i++) {
            if (s[i] != 'a') 
                return false;
        }

        return true;
    }
};
