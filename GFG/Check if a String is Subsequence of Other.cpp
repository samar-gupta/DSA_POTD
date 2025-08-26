//Approach-1 : 
//T.C : O(n+m)
//S.C : O(1)
class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int n = s1.size(), m = s2.size();
        int i = 0, j = 0;
        
        while(i < n and j < m){
            if(s1[i]!=s2[j]) {
                j++;
            } else {
                i++,j++;
            }
        }
        
        if(i == n) 
            return true;
           
        return false;
    }
};
