//Company Tags  : Meta
//Leetcode Link : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid

//Approach-1 (Using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int open = 0;
        
        for(char &ch : s) {
            if(ch == '(')
                st.push(ch);
            else if(!st.empty())
                st.pop();
            else
                open++;
        }
        
        return open + st.size();
    }
};


//Approach-2 (without using stack)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int size = 0;
        int open = 0;

        for(char &ch : s) {
            if(ch == '(') {
                size++;
            } else if(size > 0) {
                size--;
            } else {
                open++;
            }
        }

        return open + size;
    }
};
