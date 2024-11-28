//old-version
//T.C : O(n)
//S.C : O(1)
class Solution{
  public:
    int atoi(string s) {
        int ans = 0;
        int sign = 1;
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '-' && i == 0) {
                sign = -1;
            }
            else if(s[i] >= '0' && s[i] <= '9') {
                ans = ans * 10 + (s[i] - '0');
            }
            else return -1;
        }
        
        ans = ans * sign;
        return ans;
    }
};


//new-version
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        long long int ans = 0;
        int sign = 1;
        int i = 0;

        // Ignore leading whitespace
        while (s[i] == ' ') {
            i++;
        }

        // Check for optional '+' or '-'
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Process the numerical part
        while (s[i] >= '0' && s[i] <= '9') {
            int num = s[i] - '0';
            ans = ans * 10 + num;

            // Handle overflow/underflow
            if (sign == 1 && ans >= INT_MAX) return INT_MAX;
            if (sign == -1 && -ans <= INT_MIN) return INT_MIN;

            i++;
        }

        return sign * ans;
    }
};
