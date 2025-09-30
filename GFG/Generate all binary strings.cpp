//Approach-1 : 
class Solution {
  public:
    void solve(int n , string curr, vector<string> &res){
        if(n==0){
            res.push_back(curr);
            return;
        }
        //take 0
        solve(n-1, curr+'0', res);
        //take 1
        solve(n-1, curr+'1', res);
    }
    
    vector<string> binstr(int n) {
        // code here
        vector<string>res;
        solve(n,"", res);
        return res;
    }
};
