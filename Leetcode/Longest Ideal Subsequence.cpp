//Leetcode Link : https://leetcode.com/problems/longest-ideal-subsequence/

//Approach-1 (Using LIS code eactly)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        
        int result = 1;
        vector<int> t(n, 1);
        //t[i] = Longest Ideal Subsequence ending at index i
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                
                if(abs(s[j] - s[i]) <= k) {
                    t[i] = max(t[i], t[j]+1);
                }
            }
            result = max(result, t[i]);
        }
        
        return result;
    }
};



//Approach-2 (Optimised - Chec only those characters for s[i] such that abs(ch - s[i]) <=k)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        
        vector<int> t(26, 0);
        
        int result = 0;
        
        for(int i = 0; i < n; i++) {
            
            int curr    = s[i]-'a';
            int left    = max(0, curr-k);
            int right   = min(25, curr+k);

            int longest = 0;
            for(int j = left; j <= right; j++) {
                longest = max(longest, t[j]);
            }
            
            t[curr] = max(t[curr], longest+1);
            result = max(result, t[curr]);
        }
        
        return result;
        
    }
};
