//Leetcode Link : https://leetcode.com/problems/calculate-digit-sum-of-a-string/

//T.C: O(n)
//S.C: O(n)
class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k) {
            string nextStr;
            
            int n = s.length();
            
            for(int i = 0; i < n; i += k) {
                int sum = 0;
                
                for(int j = i; j < min(i+k, n); j++) { 
                    sum += s[j]-'0'; 
                } 
                nextStr += to_string(sum);
            }
            
            s = move(nextStr); //avoids copy
        }
        
        return s;
    }
};
