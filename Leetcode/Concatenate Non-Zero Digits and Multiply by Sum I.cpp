//Leetcode Link : https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/description/

//Approach-1
//T.C: O(d), d = number of digits in n
//S.C: O(d), d = number of digits in n
class Solution {
public:
    typedef long long ll;
    
    ll sumAndMultiply(int n) {
        ll x = 0;
        ll sum = 0;
        
        for(char &ch: to_string(n)) {
            if(ch != '0') {
                sum += ch - '0';
                x = x*10 + (ch - '0');
            }
        }
        
        return x * sum;
    }
};


//Approach-2
//T.c : O(d), d = number of digits in n
//S.c : O(1)
class Solution {
public:
    typedef long long ll;

    ll sumAndMultiply(int n) {
        ll x = 0;
        ll sum = 0;
        ll pow10 = 1;

        while (n > 0) {
            int digit = n % 10;

            sum += digit;

            if (digit > 0) {
                x += digit * pow10;
                pow10 *= 10;
            }

            n /= 10;
        }

        return x * sum;
    }
};
