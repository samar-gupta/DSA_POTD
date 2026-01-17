//Approach:
class Solution {
  public:
  
    bool isOperator(char ch)
    {
        if((ch=='+') || (ch=='-') || (ch=='/') || (ch=='*'))
        {
            return true;
        }
        return false;
    }
    bool checkRedundancy(string &s) {
        // code here
         stack<pair<char,int>>st;
         for(char ch:s)
         {
             if(ch=='(')
             {
                 st.push({'(',0});
             }
             else if(isOperator(ch))
             {
                 if(!st.empty())
                 {
                     st.top().second++;
                 }
             }
             else if(ch==')')
             {
                 if(st.empty())
                 {
                     return true;
                 }
                 else{
                     if(st.top().second==0)
                     {
                         return true;
                     }
                     else{
                         st.pop();
                     }
                 }
             }
         }
         return false;
    }
};


//Approach:
class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<char> st;
        for (char ch : s) {
            if (ch == ')') {
                char top = st.top(); st.pop();
                bool hasOperator = false;
                while (!st.empty() && top != '(') {
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        hasOperator = true;
                    }
                    top = st.top(); st.pop();
                }
                if (!hasOperator) return true;
            } else {
                st.push(ch);
            }
        }
        return false;
    }
};
