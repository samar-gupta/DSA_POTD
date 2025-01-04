//Company Tags  : META, AMAZON, GOOGLE
//Leetcode Link : https://leetcode.com/problems/unique-length-3-palindromic-subsequences

//Approach-1
//T.C : O(n)
//S.C : O(1) - Only 26 sized always
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<char> unique_letters;
        
        for(char &ch : s) {
            unique_letters.insert(ch);
        }
        
        int result = 0;
        
        for(char letter : unique_letters) {
            
            int first_idx = -1;
            int last_idx  = -1;
            
            for(int i = 0; i<n; i++) {
                if(s[i] == letter) {
                    
                    if(first_idx == -1) {
                        first_idx = i;
                    }
                    
                    last_idx = i;
                    
                }
            }
            
                            
            unordered_set<char> st;
            for(int middle = first_idx+1; middle <= last_idx-1; middle++) {
                st.insert(s[middle]);
            }

            result += st.size();
            
        }
        
        return result;
    }
};


//Approach-2 (Storing first and last indices before hand
//T.C : O(n)
//S.C : O(1) - Only 26 sized always
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<pair<int, int>> indices(26, {-1, -1});
        
        for(int i = 0; i<n; i++) {
            char ch = s[i];
            int idx = ch-'a';
            
            if(indices[idx].first == -1) {
                indices[idx].first = i;
            }
            
            indices[idx].second = i;
        }
        
        
        int result = 0;
        for(int i = 0; i<26; i++) {
            if(indices[i] == make_pair(-1, -1)) {
                continue;
            }
            
            unordered_set<char> st;
            for(int middle = indices[i].first+1; middle <= indices[i].second-1; middle++) {
                
                st.insert(s[middle]);
                
            }
            
            result += st.size();
        }
        
        return result;
    }
};
