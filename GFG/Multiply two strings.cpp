class Solution {
  public:
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        // Your code here
        if(s1 == "0" || s2 == "0"){
           return "0";
       }
       int flag = 0;
        if(s1[0]=='-'){
            flag++;
            s1 = s1.substr(1,s1.size()-1);
        }
          
        if(s2[0]=='-'){
            flag++;
            s2 = s2.substr(1,s2.size()-1);
        }
       vector<int> ans(s1.size()+s2.size(), 0);
       for(int i=s1.size()-1 ; i>=0 ; i--){
           for(int j=s2.size()-1 ; j>=0 ; j--){
               ans[i+j+1] += (s1[i]-'0') * (s2[j] - '0');
               ans[i+j] += ans[i+j+1]/10;
               ans[i+j+1] %= 10;
           }
       }
       int i=0;
       while(i<ans.size() && ans[i] == 0){
           i++;
       }
       string sol = "";
       for(int j=i ; j<ans.size() ; j++){
           sol.push_back(ans[j] + '0');
       }
       if(flag == 1){
           sol = "-" + sol;
       }
       return sol;
    }
};
