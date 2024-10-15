//Leetcode Link : https://leetcode.com/problems/separate-black-and-white-balls

//Approach-1 (straight forward traversal)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();

        long long swap  = 0;
        int black = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '0') { //move white to left
                swap += black;
            } else {
                black++;
            }
        }

        return swap;
    }
};


//Approach-2 (Reversed traversal)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();

        long long swap  = 0;
        int white = 0;

        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '1') { //move black to right
                swap += white;
            } else {
                white++;
            }
        }

        return swap;
    }
};
