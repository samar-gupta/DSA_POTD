//Leetcode Link               : https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i
//                            : https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii

//Approach-1 (Brute Force - Try all possible substrings)
//T.C : O(n^3)
//S.C : O(n^2), total substrings
class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();

        map<string, int> mp; //"substring, int"
        for(int i = 0; i < n; i++) {
            string curr;
            for(int j = i; j < n; j++) {
                if(curr.empty() || curr.back() == s[j]) {
                    curr.push_back(s[j]);
                    mp[curr]++;
                } else {
                    break;
                }
            }
        }

        int result = 0;
        for(auto &it : mp) {
            string str = it.first;
            int count = it.second;
            if(count >= 3 && str.length() > result) {
                result = str.length();
            }
        }

        return result == 0 ? -1 : result;
                
    }
};


//Approach-2 (Better Brute Force)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();

        map<pair<char, int>, int> mp;

        for(int i = 0; i < n; i++) {
            char ch = s[i];
            int l = 0;
            for(int j = i; j < n; j++) {
                if(s[j] == ch) {
                    l++;
                    mp[{ch, l}]++;
                } else {
                    break;
                }
            }
        }


        int result = 0;
        for(auto &it : mp) {
            //char ch = it.first.first;
            int length = it.first.second;
            int freq = it.second;

            if(freq >= 3 && length > result) {
                result = length;
            }
        }

        return result == 0 ? -1 : result;
    }
};


//Approach-3 (Optimal - using a 2-d substring store)
//T.C : O(n)
//S.C : O(26*n) ~ O(n)
class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();

        vector<vector<int>> matrix(26, vector<int>(n+1, 0));
        
        char prev_char = s[0];
        int length = 0;

        for(int i = 0; i < n; i++) {
            char curr_char = s[i];

            if(curr_char == prev_char) {
                length += 1;
                matrix[curr_char-'a'][length] += 1;
            } else {
                length = 1;
                matrix[curr_char-'a'][length] += 1;
                prev_char = curr_char;
            }
        }


        int result = 0;
        for(int i = 0; i < 26; i++) {
            int cumSum = 0;
            for(int j = n; j >= 1; j--) {
                cumSum += matrix[i][j];
                if(cumSum >= 3) {
                    result = max(result, j);
                    break;
                }
            }
        }
        return result == 0 ? -1 : result;
    }
};
