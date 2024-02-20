class Solution {
public:
    bool solve(int idx,int n,string s,unordered_set<string> st)
    {
        if(idx == n) 
            return true;
        
        string k;
        
        for(int l=1; idx+l<=n; l++)
        {
            k = s.substr(idx,l);
            if(st.find(k) != st.end())
            {
                if(solve(idx+l,n,s,st) == true)
                return true;
            }
        }
        
        return false;
    }
    
    int wordBreak(int n, string s, vector<string> &dictionary) {
        unordered_set<string> st;
        for(int i=0; i<n; i++) {
            st.insert(dictionary[i]);
        }
        bool ans = solve(0,s.size(),s,st);
        return ans;
    }
};
