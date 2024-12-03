//Leetcode Link : https://leetcode.com/problems/adding-spaces-to-a-string

//Approach (Simple traversal using two pointers)
//T.C : O(m+n)
//S.C : O(1)
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int m = s.length();
        int n = spaces.size();

        string result = "";

        int j = 0; //to traverse in spaces vector
        for(int i = 0; i < m; i++) {
            if(j < n && i == spaces[j]) {
                result += " ";
                j++;
            }

            result += s[i];
        }

        return result;
    }
};
