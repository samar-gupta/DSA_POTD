//Company Tags  : Most asked online Assessment Qn of Amazon in year 2022 (Karat, Amazon, Uber, Pinterest)
//Leetcode Link : https://leetcode.com/problems/largest-3-same-digit-number-in-string

//Approach : Simple iteration and check
class Solution {
public:
    string largestGoodInteger(string num) {
        char maxChar = ' ';
        
        for(int i = 2; i<num.length(); i++) {
            if(num[i] == num[i-1] && num[i] == num[i-2]) {
                maxChar = max(maxChar, num[i]);
            }
        }
        
        return maxChar == ' ' ? "" : string(3, maxChar);
    }
};


//Java
//Simple iteration and check
public class Solution {
    public String largestGoodInteger(String num) {
        char maxChar = ' ';
        
        for (int i = 2; i < num.length(); i++) {
            if (num.charAt(i) == num.charAt(i - 1) && num.charAt(i) == num.charAt(i - 2)) {
                maxChar = (char) Math.max(maxChar, num.charAt(i));
            }
        }
        
        return maxChar == ' ' ? "" : new String(new char[] { maxChar, maxChar, maxChar });
    }
}


//Python
class Solution(object):
    def largestGoodInteger(self, num):
        """
        :type num: str
        :rtype: str
        """
        max_char = ''
        for i in range(2, len(num)):
            if num[i] == num[i - 1] == num[i - 2]:
                max_char = max(max_char, num[i])
        return '' if max_char == '' else max_char * 3
  
