//Approach-1 : (Using Recursion)
class Solution {
  public:
    void rec(string str, int k, int a, string &ans){
        ans=max(ans,str);
        if(k==0) return;
        for(int i=a;i<str.length()-1;i++){
            for(int j=i+1;j<str.length();j++){
                if(str[j]>str[i]){
                    swap(str[i],str[j]);
                    rec(str,k-1,i+1,ans);
                    swap(str[i],str[j]);
                }
            }
        }
    }
    
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& str, int k) {
        // code here.
        string ans=str;
        rec(str,k,0,ans);
        return ans;
    }
};


//Approach-2 : 
class Solution {
  public:
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // code here.
        int n=s.size();
        int i=0;
        while(i<n && k!=0){
            int tempMax=s[n-1]-'0';
            
            int ind=n-1;
            for(int j=n-1;j>=i;j--){
                if(tempMax<s[j]-'0'){
                  tempMax=s[j]-'0';
                  ind=j;
                } 
            }
            if(s[i]-'0'>=tempMax){
                i++;
                continue;
            } 
            else{
                char temp=s[i];
                s[i]=s[ind];
                s[ind]=temp;
                i++;
                k--;
            }
        }
        return s;
    }
};
