//Approach-1 : 
//T.C-> O(N*M)
class Solution {
  public:
    void solve(int i, int n, vector<int>&arr, string temp, vector<string>&ans, vector<string>keys) {
        //base case
        if(i==n) {
            ans.push_back(temp);
            return;
        }
        
         // if digit is 0 or 1 (no mapping), just skip
        if (keys[arr[i]].empty()) {
            solve(i + 1, n, arr, temp, ans, keys);
            return;
        }
        
        for(int j=0; j<keys[arr[i]].size(); j++) {
            solve(i+1, n, arr, temp+keys[arr[i]][j], ans, keys);
        }
    }
    
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        vector<string>keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>ans;
        solve(0, arr.size(), arr, "", ans, keys);
        return ans;
    }
};


//Approach-1 : 
class Solution {
  public:
    void solve(int i ,vector<int> &arr,vector<string>&ans,string& s,unordered_map<int,string>&map){
        if(i>=arr.size()){
            ans.push_back(s);
            return;
        }
        int n = arr[i];
        if(n==1 || n==0){
            solve(i+1,arr,ans,s,map);
        }
        for(int j =0;j<map[n].size();j++){
            s.push_back(map[n][j]);
            solve(i+1,arr,ans,s,map);
            s.pop_back();
        }
    }
    
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        unordered_map<int,string>map;
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";
        vector<string>ans;
        string s;
        solve(0,arr,ans,s,map);
        return ans;
    }
};


//Approach-1 :
class Solution {
  public:
    void fun(int i, int n, string s, vector<int> &v, vector<string> &ans, map<int, vector<char>> &m) {
        if(i==n) {
            ans.push_back(s);
            return;
        }    
        if(v[i]==0 || v[i]==1) return fun(i+1, n, s, v, ans, m);
        
        for(int j=0; j<m[v[i]].size(); j++) {
            fun(i+1, n, s+m[v[i]][j], v, ans, m);
        }
    }
    
    vector<string> possibleWords(vector<int> &v) {
        // code here
        int n = v.size();
        vector<string> ans;
        
        map<int, vector<char>> m;
        m[2]={'a','b','c'};
        m[3]={'d','e','f'};
        m[4]={'g','h','i'};
        m[5]={'j','k','l'};
        m[6]={'m','n','o'};
        m[7]={'p','q','r','s'};
        m[8]={'t','u','v'};
        m[9]={'w','x','y','z'};
        
        fun(0, n, "", v, ans, m);
        return ans;
    }
};
