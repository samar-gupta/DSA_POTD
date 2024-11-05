//Leetcode Link : https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful

//Approach-1 (Simple iterate and count and keep track)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minChanges(string s) {
        char curr = s[0];

        int count = 0;
        int changes = 0;
        int n = s.length();

        // Iterate through each character in the string
        for (int i = 0; i < n; i++) {

            if (s[i] == curr) {
                count++;
                continue;
            }

            if (count % 2 == 0) { //Even
                count = 1;
            } else { //Odd
                count = 0;
                changes++;
            }
            
            curr = s[i];
        }

        return changes;
    }
};


//Approach-2 (Simple iterate and count and keep track)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        int n = s.length();

        for (int i = 0; i < n; i += 2) {

            if (s[i] != s[i + 1]) {
                changes++;
            }
        }

        return changes;
    }
};
