class Solution {
  public:
    int expand(int l,int r,string s){
        int cnt=0;
        int n=s.length();
        while(l>=0 && r<n && s[l]==s[r]){
            if(r-l>=1) cnt++;
            l--;
            r++;
        }
        return cnt;
    }
    
    int countPS(string &s) {
        // code here
        // centre expansion method
        int ans=0;
        int n=s.length();
        for(int i=0;i+1<n;i++){
            // consider a single centre
            ans+=expand(i,i,s);
            // consider 2 centres
            ans+=expand(i,i+1,s);
        }
        return ans;
    }
};
