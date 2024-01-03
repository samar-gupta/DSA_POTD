//Approach : Traversing untill all are found and then shrinking size from left , if (count of any < 1) then expanding to right side 
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int smallestSubstring(string S) {
        int n = S.size();
        int ans = -1;
        int one = 0, two = 0, zero = 0;
        int l = 0, r = 0;
        
        for(r = 0; r < n; r++) {
            if(S[r] == '0') zero++;
            else if(S[r] == '1') one++;
            else two++;
            
            while(one>=1 && two>=1 && zero>=1) {
                if(ans == -1) {
                    ans = r - l + 1;
                } else {
                    ans = min(ans, r - l + 1);
                }
                
                if(S[l] == '0') 
                    zero--;
                else if(S[l] == '1') 
                    one--;
                else 
                    two--;

                l++;
            }
            
        }
        
        return ans;
    }
};
