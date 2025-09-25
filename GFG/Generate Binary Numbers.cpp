//Approach-1 : (Using Queue)
class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        vector<string> res;
        queue<string> q;
        q.push("1");
        
        while(n--) {
            string s = q.front();
            q.pop();
            res.push_back(s);
            
            if(q.size() < n) {
                q.push(s+"0");
                q.push (s+"1");
            }
        }
        return res;
    }
};
