//Company Tags  : GOOGLE, AMAZON
//Leetcode Link : https://leetcode.com/problems/longest-palindrome/description

//Approach-1 (Using simple set)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_set<char> st;

        int result = 0;
        for(char &ch : s) {
            if(st.count(ch)) {
                st.erase(ch);
                result += 2;
            } else {
                st.insert(ch);
            }
        }

        if(!st.empty())
            result++;
        
        return result;
    }
};


//Approach-2 (Using hashmap and countintg frequency)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<char, int> mp;

        int result = 0;
        for(char &ch : s) {
            mp[ch]++;
        }

        bool takeCentralChar = false;
        for(auto &it : mp) {
            if(it.second % 2 == 0) {
                result += it.second;
            } else {
                result += it.second - 1;
                takeCentralChar = true;
            }
        }

        if(takeCentralChar)
            result++;

        return result;
    }
};



//Approach-3 (one iteration) as it took two iterations in approach-2
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<char, int> mp;

        int result  = 0;
        int oddFrq  = 0;

        for(char &ch : s) {
            mp[ch]++;

            if(mp[ch] % 2 != 0) {
                oddFrq++;
            } else {
                oddFrq--;
            }
        }

        if(oddFrq > 0) {
            return n - oddFrq + 1;
        }

        return n;
    }
};
