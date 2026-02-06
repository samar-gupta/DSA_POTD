class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        int i = 0;
        int j = 0;
        int k = 0;
        vector<int>v;
        int ans = INT_MAX;
        while(i<a.size() && j<b.size() && k<c.size()){
            int mn = INT_MAX;
            int mx = INT_MIN;
            int a1 = a[i];
            int b1 = b[j];
            int c1 = c[k];
            mn = min(mn,min(a1,b1));
            mn = min(mn,c1);
            mx = max(mx,max(a1,b1));
            mx = max(mx,c1);
            int f = ans;
            ans = min(ans,mx-mn);
            if(f != ans){
                v.clear();
                v.push_back(a1);
                v.push_back(b1);
                v.push_back(c1);
            }
            if(mn == a1){
                i++;
            }
            else if(mn == b1){
                j++;
            }
            else{
                k++;
            }
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        return v;
    }
};
