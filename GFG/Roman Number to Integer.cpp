//Approach-1 : (Using Hashmap)
/*Intuition - In Roman numerals, if a smaller numeral comes before a larger numeral, it is subtracted, 
              otherwise, they are added to get the integer value. 
    eg:  IV => I (1) is less than V (5) => 5-1 = 4
         VI => V(5) is more than I (1) => 5+1 = 6
*/
//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int romanToDecimal(string &s) {
       // code here
       int n = s.length();
       int ans=0;
       unordered_map<char,int> num;
       num['I'] = 1;
       num['V'] = 5;
       num['X'] = 10;
       num['L'] = 50;
       num['C'] = 100;
       num['D'] = 500;
       num['M'] = 1000;
       
       for(int i=n-1;i>=0;i--){
           if(i<n-1 && num[s[i]]<num[s[i+1]])
               ans-=num[s[i]];
           else{
               ans+=num[s[i]];
           }
       }
       
       return ans;
    }
};


//Approach-2 : 
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
  
    int value(char ch){
        if(ch == 'I') return (1);
        if(ch == 'V') return (5);
        if(ch == 'X') return (10);
        if(ch == 'L') return (50);
        if(ch == 'C') return (100);
        if(ch == 'D') return (500);
        if(ch == 'M') return (1000);
        return (0);
    }
    
    int romanToDecimal(string &s) {
        // code here
        int ans = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(i < n-1 && value(s[i]) < value(s[i+1])){
                ans += value(s[i+1]) - value(s[i]);
                i++;
            }
            else{
                ans += value(s[i]);
            }
        }
        return (ans);
    }
};



//old
class Solution {
  public:
    int romanToDecimal(string &s) {
        unordered_map<char,int> mp {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        int ans = 0;
        int n = s.length();
        
        ans += mp[s[n-1]];
        int prev = mp[s[n-1]];
        for(int i=n-2; i>=0; i--) {
            if(mp[s[i]] >= prev) {
                ans += mp[s[i]];
            }
            else {
                ans -= mp[s[i]];
            }
            prev = mp[s[i]];
        }
        return ans;
    }
};
