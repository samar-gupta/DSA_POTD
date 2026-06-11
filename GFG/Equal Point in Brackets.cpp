class Solution {
  public:
    int findIndex(string &str) {
        // code here
        int close = count(str.begin(),str.end(),')');
        int open = 0;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]==')')
                close--;
            else
                open++;
            if(open==close)
                return i+1;
        }
        return 0;
    }
};
