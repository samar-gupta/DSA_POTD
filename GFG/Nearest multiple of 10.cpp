class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int n = str.size() - 1;
        int last = str[n] - '0';
        
        if(last == 0) {
            return str;
        }
        
        if(last <= 5) {
            str[n] = '0';
            return str;
        }
        
        str[n] = '0';
        int i = 1;
        
        while(n - i >= 0 && str[n - i] == '9') {
            str[n - i] = '0';
            i++;
        }
        
        if(n - i < 0) {
            str = '1' + str;
        } else {
            str[n - i] = str[n - i] + 1;
        }
        
        return str;
    }
};
