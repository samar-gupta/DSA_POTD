//Leetcode Link : https://leetcode.com/problems/count-the-number-of-consistent-strings

//Approach-1 (using hashset)
//T.C : O(m + n*k)
//S.C : O(m)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st(begin(allowed), end(allowed));

        int count = 0;
        for(string &word : words) {
            bool allChar = true;

            for(char &ch : word) {
                if(!st.count(ch)) {
                    allChar = false;
                    break;
                }
            }

            count += allChar;
        }

        return count;
    }
};


//Approach-2 (using boolean array)
//T.C : O(m + n*k)
//S.C : O(m)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> isAllowed(26, false);
        for(char &ch : allowed) {
            isAllowed[ch - 'a'] = true;
        }

        int count = 0;
        for(string &word : words) {
            bool allChar = true;

            for(char &ch : word) {
                if(!isAllowed[ch-'a']) {
                    allChar = false;
                    break;
                }
            }

            count += allChar;
        }

        return count;
    }
};


//Approach-3 (using bit magic)
//T.C : O(m + n*k)
//S.C : O(1)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;

        //create mask
        for (char &ch : allowed) {
            mask |= 1 << (ch - 'a');
        }

        int count = 0;

        for (string& word : words) {
            bool allChar = true;

            // Check each character in the word
            for (int i = 0; i < word.length(); i++) {

                //check if the bit is set
                if (((mask >> (word[i] - 'a')) & 1) == 0) {
                    allChar = false;
                    break;
                }
            }

            if (allChar) {
                count++;
            }
        }

        return count;
    }
};
