//Approach:
class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        stack<char>st;
        for(char ch:s)
        {
            while(!st.empty() && (st.top()>ch) && (k>0))
            {
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while(k>0 && !st.empty())
        {
            st.pop();
            k--;
        }
        
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        int idx=-1;
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]!='0')
            {
                idx=i;
                break;
            }
        }
        if(idx==-1)
        {
            return "0";
        }
        return ans.substr(idx);
    }
};


//old
class Solution {
  public:
    string removeKdigits(string S, int k) {
    int n = S.length();
    if (k == n) {
        return "0";
    }
    stack<char> st;
    for (char digit : S) {
        while (!st.empty() && k > 0 && st.top() > digit) {
            st.pop();
            k--;
        }
        st.push(digit);
    }
    while (k > 0) {
        st.pop();
        k--;
    }
    string ans = "";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    int len=ans.length();
    int startIndex = len;
    for (int  i = 0; i <len; i++) {
        if (ans[i] != '0') {
            startIndex = i;
            break;
        }
    }
    ans = (startIndex ==len ) ? "0" : ans.substr(startIndex);
    return ans;
    }
};
