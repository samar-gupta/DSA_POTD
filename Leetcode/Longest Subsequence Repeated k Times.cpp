//Leetcode Link : https://leetcode.com/problems/longest-subsequence-repeated-k-times/

//Approach-1 (Khandani Backtracking remplate - storing all possible strings)
//T.C : O(n * ((n/k)!))
//S.C : O(n/k)
class Solution {
public:
    string result = "";

    bool isSubsequence(string &s, string& sub, int k) {
        int i = 0;
        int j = 0;
        int L = sub.length();
        int n = s.length();

        while(i < n && j < k*L) {
            if(s[i] == sub[j%L])
                j++;
            
            i++;
        }

        return j == k * L;
    }

    bool backtracking(string& s, string &curr, vector<bool>& canUse, vector<int>& requiredFreq, int k, int maxLen) {
        if(curr.length() == maxLen) {
            if(isSubsequence(s, curr, k)) {
                result = curr;
                return true;
            }
            return false;
        }

        for(int i = 25; i >= 0; i--) {
            if(canUse[i] == false || requiredFreq[i] == 0)
                continue;
            
            //DO
            char ch = i + 'a';
            curr.push_back(ch);
            requiredFreq[i]--;

            //EXPLORE
            if(backtracking(s, curr, canUse, requiredFreq, k, maxLen) == true) {
                return true;
            }

            //UNDO
            curr.pop_back();
            requiredFreq[i]++;

        }

        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();

        int freq[26] = {};
        for(char &ch : s) {
            freq[ch-'a']++;
        }

        vector<bool> canUse(26, false);
        vector<int> requiredFreq(26, 0);
        for(int i = 0; i < 26; ++i) {
            if(freq[i] >= k) {
                canUse[i] = true;
                requiredFreq[i] = freq[i]/k; //atmost this can be used in a subsequence
            }
        }

        int maxLen = n / k;

        for(int len = maxLen; len >= 0; len--) {
            vector<int> tempRequiredFreq = requiredFreq;
            string curr = "";
            if(backtracking(s, curr, canUse, tempRequiredFreq, k, len) == true) {
                return result;
            }
        }

        return result;


    }
};


//Approach-2 IMPROVED BACKTRACKING : (Khandani Backtracking remplate - storing all possible strings)
//T.C : O(n * ((n/k)!))
//S.C : O(n/k)
class Solution {
public:
    string result = "";

    bool isSubsequence(string &s, string& sub, int k) {
        int i = 0;
        int j = 0;
        int L = sub.length();
        int n = s.length();

        while(i < n && j < k*L) {
            if(s[i] == sub[j%L])
                j++;
            
            i++;
        }

        return j == k * L;
    }

    void backtracking(string& s, string &curr, vector<bool>& canUse, vector<int>& requiredFreq, int k, int maxLen) {
        if(curr.length() > maxLen)
            return;
        
        if((curr.length() > result.length() || (curr.length() == result.length() && curr > result))
            && isSubsequence(s, curr, k)) {
                result = curr;
        }

        for(int i = 0; i <= 25; i++) {
            if(canUse[i] == false || requiredFreq[i] == 0)
                continue;
            
            //DO
            char ch = i + 'a';
            curr.push_back(ch);
            requiredFreq[i]--;

            //EXPLORE
            backtracking(s, curr, canUse, requiredFreq, k, maxLen);

            //UNDO
            curr.pop_back();
            requiredFreq[i]++;

        }

    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();

        int freq[26] = {};
        for(char &ch : s) {
            freq[ch-'a']++;
        }

        vector<bool> canUse(26, false);
        vector<int> requiredFreq(26, 0);
        for(int i = 0; i < 26; ++i) {
            if(freq[i] >= k) {
                canUse[i] = true;
                requiredFreq[i] = freq[i]/k; //atmost this can be used in a subsequence
            }
        }

        int maxLen = n / k;

        string curr;
        backtracking(s, curr, canUse, requiredFreq, k, maxLen);

        return result;


    }
};
