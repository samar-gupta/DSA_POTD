class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        set<int> st;
        int n=a.size();
        int m=b.size();
        for(auto it:a)
        {
            st.insert(it);
        }
        vector<int> ans;
        for(auto it:b)
        {
            if(st.find(it)!=st.end())
            {
                ans.push_back(it);
                st.erase(it);
            }
        }
        return ans;
    }
};
