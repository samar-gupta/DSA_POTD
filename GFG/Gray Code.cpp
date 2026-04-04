class Solution {
  public:
    vector<string> graycode(int n) {
        // code here
        if(n==1)
        {
            return {"0","1"};
        }
        vector<string> last=graycode(n-1);
        vector<string>ans;
        for(int i=0;i<last.size();i++)
        {
            string curr='0'+last[i];
            ans.push_back(curr);
        }
        for(int i=last.size()-1;i>=0;i--)
        {
            string curr='1'+last[i];
            ans.push_back(curr);
        }
        return ans;
    }
};
