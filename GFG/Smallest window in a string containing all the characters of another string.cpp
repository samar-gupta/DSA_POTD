//Approach-1 :
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int>freq(26,0);
        int cnt=0;
        for(int i=0;i<p.length();i++){
            if(freq[p[i]-'a']==0) cnt++;
            freq[p[i]-'a']++;
        }
        
        int j=0,i=0;
        int ans=INT_MAX,start=0;
        
        while(j<s.length()){
            
            freq[s[j]-'a']--;
            if(freq[s[j]-'a']==0) cnt--;
            
            if(cnt==0){
                
                while(cnt==0){
                    if(ans>j-i+1){
                        ans=min(ans,j-i+1);
                        start=i;
                    }
                    freq[s[i]-'a']++;
                    if(freq[s[i]-'a']==1) cnt++;
                    i++;
                }
                
            }
            j++;
        }
        
        if(ans==INT_MAX) 
            return "-1";
            
        return s.substr(start,ans);
    }
};


//Approach-2 :
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int minLen = INT_MAX;
        int sind = -1;
        int r = 0 , l = 0;
        vector<int> mp(256,0);
        for(int i=0;i<p.size();i++){
            mp[p[i]]++;
        }
        int cnt  =0;
        while(r<s.length()){
            if(mp[s[r]] > 0){
                cnt++;
            }
            mp[s[r]]--;
            while(cnt == p.length()){
                if(r-l+1 < minLen){
                    minLen = r - l +1;
                    sind = l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return sind == -1 ? "-1" : s.substr(sind,minLen);
    }
};
