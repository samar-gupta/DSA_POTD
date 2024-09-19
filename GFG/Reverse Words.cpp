class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        string ans="";
        stringstream ss(str);
        string word;
        while(getline(ss,word,'.')){
            ans=word+"."+ans;
        }
        ans.pop_back();
        return ans;
    }
};
