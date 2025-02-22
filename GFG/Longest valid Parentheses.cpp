//Approach-1 :
class Solution {
  public:
    int maxLength(string& str) {
        // code here
        int n = str.size();
        stack<int> st;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(str[i] == '(')
            {
                st.push(i);
            }
            else
            {
                if(!st.empty() && str[st.top()] == '(')
                {
                    st.pop();
                    int first = st.empty() ? -1 : st.top();
                    ans = max(ans,i-first);
                }
                else 
                {
                    st.push(i);
                }
            }
        }
        return ans;
    }
};


//Approach-2 :
class Solution {
  public:
    int maxLength(string& arr) {
        // code here
        int n  = arr.length();
        int open = 0, close = 0;
        int ans = 0;
        
        for(int i = 0;i<n;i++)
        {
            if(arr[i] == '(')
                open++;
            else
                close++;
            if(open == close)
                ans = max(ans, open+close);
            else if(close > open)
            { 
                open = 0;
                close = 0;
            }
        }
        
        open = 0;
        close = 0;
        
        for(int i = n-1;i>=0;i--)
        {
            if(arr[i] == '(')
                open++;
            else
                close++;
            if(open == close)
                ans = max(ans, open+close);
            else if(open > close)
            {
                open = 0;
                close = 0;
            }
        }
        
        return ans;
    }
};


//Approach-2 : 
class Solution {
  public:
    int maxLength(string& s) {
        // code here
        int n = s.length();
        int open = 0, close = 0, ans = 0;

        // Left to Right
        for(int i = 0; i < n; i++){
            if(S[i] == '(')
                open++;
            else
                close++;

            if(open == close)
                ans = max(ans, open * 2);
            else if(close > open)
                open = close = 0;
        }

        // Right to Left
        open = close = 0;
        for(int i = n - 1; i >= 0; i--){
            if(S[i] == '(')
                open++;
            else
                close++;

            if(open == close)
                ans = max(ans, open * 2);
            else if(open > close)
                open = close = 0;
        }

        return ans;
    }
};


//Approach-1 : 
class Solution {
  public:
    int maxLength(string& s) {
        // code here
        stack<int> st;
        st.push(-1);
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ')' && st.size() > 1 && s[st.top()] == '(') {
                st.pop();
            } else {
                st.push(i);
            }
        }
        int lim = s.length(), ans = 0;
        while(!st.empty()) {
            int p = st.top();
            st.pop();
            ans = max(ans, lim - p - 1);
            lim = p;
        }
        return ans;
    }
};
