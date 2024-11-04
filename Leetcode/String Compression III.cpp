//Leetcode Link : https://leetcode.com/problems/string-compression-iii

//Approach (Simple Simulation)
//T.C : O(n)
//S.C : O(1)  //not including result string "comp"
class Solution {
public:
    string compressedString(string word) {
        string comp = "";

        int n = word.length();
        int i = 0;

        while(i < n) {
            int count = 0;
            char ch   = word[i];

            while(i < n && count < 9 && word[i] == ch) {
                count++;
                i++;
            }

            comp += to_string(count) + ch;
        }

        return comp;
    }
};
