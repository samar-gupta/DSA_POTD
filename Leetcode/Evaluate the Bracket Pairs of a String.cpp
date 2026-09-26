//Leetcode Link : https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string

//Approach-1
//T.C : O(n+m) //TRaversing all characters in s and knowledge
//S.C : O(n+m)
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        unordered_map<string, string> mp;


        for(auto &vec : knowledge) {
            mp[vec[0]] = vec[1];
        }

        string result = "";
        int i = 0;
        while(i < n) {
            if(isalpha(s[i])) {
                result.push_back(s[i]);
            } else { //(
                i++;
                string temp = "";
                while(i < n && s[i] != ')') {
                    temp.push_back(s[i]);
                    i++;
                }
                result += mp.count(temp) ? mp[temp] : "?";
            }
            i++;
        }

        return result;
    }
};



//Approach-2
//T.C : O(n+m) //TRaversing all characters in s and knowledge
//S.C : O(n+m)
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        unordered_map<string, string> mp;


        for(auto &vec : knowledge) {
            mp[vec[0]] = vec[1];
        }

        string result = "";
        string temp = "";
        bool bracketOpened = false;
        int i = 0;
        
        while(i < n) {
            if(s[i] == '(') {
                bracketOpened = true;
            } else if(s[i] == ')') {
                result += mp.count(temp) ? mp[temp] : "?";
                bracketOpened = false;
                temp = "";
            } else if(bracketOpened) {
                temp.push_back(s[i]);
            } else {
                result.push_back(s[i]);
            }

            i++;
        }

        return result;
    }
};




//Approach-3
//T.C : O(n+m) //TRaversing all characters in s and knowledge
//S.C : O(n+m)
class Solution {
public:
    //Code 3
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();

        unordered_map<string, string> mp;

        for(auto &vec : knowledge) {
            //vec[0], vec[1]
            mp[vec[0]] = vec[1];
        }

        string result = "";
        int i = 0;

        while(i < n) {
            if(s[i] == '(') {
                int j = s.find(")", i+1);
                string temp = s.substr(i+1, j-i-1);
                result += mp.count(temp) ? mp[temp] : "?";
                i = j;
            } else {
                result.push_back(s[i]);
            }

            i++;
        }
        return result;
    }
};
