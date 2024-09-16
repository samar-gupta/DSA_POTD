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
