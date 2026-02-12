//Leetcode Link : https://leetcode.com/problems/longest-balanced-substring-i

//Approach (try all subarrays)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:

    bool checkBalanced(vector<int>& freq) {
        int common = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;
            if(common == 0)
                common = freq[i];
            else if(freq[i] != common) {
                return false;
            }
        }

        return true;
    }

    int longestBalanced(string s) {
        int n = s.length();

        int maxL = 0;

        for(int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                //i..j
                if(checkBalanced(freq)) {
                    maxL = max(maxL, j-i+1);
                }
            }
        }

        return maxL;
    }
};
