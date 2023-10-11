//Approach-1 (Brute Force) - TLE
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n = people.size();
        
        vector<int> result(n);
        
        for(int i = 0; i<n; i++) {
            
            for(int j = 0; j<m; j++) {
                int start = flowers[j][0];
                int end   = flowers[j][1];
                
                if(people[i] >= start && people[i] <= end) {
                    result[i]++;
                }
                
            }
            
        }
        
        return result;
    }
};
