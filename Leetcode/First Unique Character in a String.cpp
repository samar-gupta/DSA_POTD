//Company Tags   : Amazon
//Leetcode Link  : https://leetcode.com/problems/first-unique-character-in-a-string/

//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};

        int n = s.length();

        for(char &ch : s) {
            arr[ch-'a']++;
        }

        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(arr[ch-'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};
