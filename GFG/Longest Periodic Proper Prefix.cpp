//Approach-1 :
class Solution {
  public:
    int getLongestPrefix(string &s) {
        // code here
        int n = s.size();
        int len = s.size()-1;
        
        while(len){
            int sPtr = len;
            int i = 0;
            
            while(sPtr<n){
                if(s[sPtr] == s[i]){
                    i++;
                    sPtr++;
                }
                else{
                    break;
                }
            }
            
            if(sPtr==n)
              return len;
            
            len--;
        }
        
        
        return -1;
    }
};


//Approach-2 :
//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    vector<int> zFunction(const string &s) { 
        int n = s.size(); 
        vector<int> z(n, 0);
        
        int l = 0, r = 0;
        for(int i = 1 ;i < n;++i) { 
            if (i <= r) { 
                z[i] = min(r-i+1, z[i-l]);
            }
            
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) { 
                z[i]++; 
            }
            
            if (i + z[i] - 1 > r) { 
                l = i; 
                r = i + z[i] - 1;
            } 
        } 
        return z;
    }
    
    int getLongestPrefix(string &s) {
        // code here
        int n = s.size(); 
        vector<int> z = zFunction(s);
        
        for(int i = n - 1; i > 0; i--) { 
            if (z[i] == n - i) { 
                return i; 
            }
        }
        return -1;
    }
};
