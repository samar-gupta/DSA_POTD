//Leetcode Link : https://leetcode.com/problems/find-the-highest-altitude/description/

//Approach : 
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAlt = 0;
        
        int curr = 0;       
        for(int &g: gain) {
            curr += g;
            
            maxAlt = max(maxAlt, curr); 
        }
        
        return maxAlt;
    }
};
