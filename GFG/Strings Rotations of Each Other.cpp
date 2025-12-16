//Approach:
class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        if ((s1+s1).find(s2)!=string::npos) 
            return true;
  
        return false;
    }
};


//Approach:
class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        if (s1.length() != s2.length())
        return false;

        string t = s1 + s1;
        return t.find(s2) < t.length();
    }
};


//Approach:
class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        s1 = s1 + s1;
        int i = 0;
        int j = 0;
        while(i < s1.size() && j < s2.size()){
            if(s1[i] == s2[j]){
                j++;
            }
            i++;
        }
        if(j == s2.size()) return true;
        return false;
    }
};


//old
class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
        if(s1.length()!=s2.length()) return false;
        string ans=s1+s1;
        return ans.find(s2)!=-1;
    }
};
