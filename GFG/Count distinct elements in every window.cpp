class Solution {
  public:
    vector<int> countDistinct(vector<int> &A, int k) {
        // code here.
        int n = A.size();
        vector<int> v;
        unordered_map<int,int> mp;
        int i=0,j=0;
        while(j<n)
        {
            mp[A[j]]++;
            if(j-i+1==k)
            {
                v.push_back(mp.size());
                mp[A[i]]--;
                if(mp[A[i]]==0)
                mp.erase(A[i]);
                i++;
            }
            j++;
        }
        return v;
    }
};
