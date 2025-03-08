class Solution {
  public:
    string longestPalindrome(string &S) {
        // code here
        int n = S.size();
        if(n == 1) return S;
        int length = 0;
        string answer = "";
        
        for(int i = 0; i < n; i++) {
            int left = i; 
            int right = i;
            
            // Odd length Palindrome
            while(left >= 0 && right < n && S[left] == S[right]) {
                if((right - left + 1) > length) {
                    length = (right - left + 1);
                    answer = S.substr(left, length);
                }
                left--; 
                right++;
            }
            
            // Even length Palindrome
            left = i;
            right = i + 1;
            while(left >= 0 && right < n && S[left] == S[right]) {
                if((right - left + 1) > length) {
                    length = (right - left + 1);
                    answer = S.substr(left, length);
                }
                left--; 
                right++;
            }
        }
        
        return answer;
    }
};
