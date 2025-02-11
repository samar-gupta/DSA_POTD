//Leetcode Link : https://leetcode.com/problems/remove-all-occurrences-of-a-substring

//Approach-1 (Brute Force)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    string removeOccurrences(string s, string part) {
        //s.length() = m
        //part.length() = n;
        //O(m*n)
        while(true) {
            int idx = s.find(part);

            if(idx == string::npos) {
                break;
            }

            s.erase(idx, part.length());
        }

        return s;
    }
};


//Approach-2 (Using Stack)
//T.C : O(m*n)
//S.C : O(m)
class Solution {
public:
    bool check(stack<char>& st, string& part, int n) {
        stack<char> tempSt = st;

        for(int idx = n-1; idx >= 0; idx--) {
            if(tempSt.top() != part[idx]) {
                return false;
            }

            tempSt.pop();
        }

        return true;
    }


    string removeOccurrences(string s, string part) {
        stack<char> st;

        int m = s.length();
        int n = part.length();

        for(int i = 0; i < m; i++) {
            st.push(s[i]);

            if(st.size() >= n && check(st, part, n) == true) {
                for(int j = 0; j < n; j++) {
                    st.pop();
                }
            } 
        }

        string result = "";
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(begin(result), end(result));
        return result;
    }
};


//Approach-3 (Using string as a stack)
//T.C : O(m*n)
//S.C : O(1), not considering result as extra space
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result = "";
        int n = part.length();

        for(char &ch : s) {
            result.push_back(ch);

            if(result.length() >= n && result.substr(result.length() - n) == part) {
                result.erase(result.length() - n);
            }
        }

        return result;
    }
};
