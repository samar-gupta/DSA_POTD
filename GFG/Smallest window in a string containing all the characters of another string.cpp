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
